#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ---- USER-DEFINED STRING FUNCTIONS ----

// Find length of string
int str_length(char s[]) {
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

// Copy string from src to dest
void str_copy(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Compare two strings
// returns 0 if equal, non-zero if different
int str_compare(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    return 0;
}

// Concatenate s2 to s1
void str_concat(char s1[], char s2[]) {
    int i = 0, j = 0;
    // Find end of s1
    while (s1[i] != '\0') i++;

    // Append s2
    while (s2[j] != '\0') {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
}

// ---- CAPTCHA GENERATOR ----
void generateCaptcha(char captcha[], int length) {
    char alphabets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int n = 52;  // total alphabets

    for (int i = 0; i < length; i++) {
        captcha[i] = alphabets[rand() % n];
    }
    captcha[length] = '\0';
}

// ---- MAIN PROGRAM ----
int main() {
    srand(time(0));

    char captcha[20];
    char userInput[20];

    // Generate 6-letter CAPTCHA
    generateCaptcha(captcha, 6);

    printf("Generated CAPTCHA: %s\n", captcha);

    printf("Enter CAPTCHA: ");
    scanf("%s", userInput);

    // Compare using user-defined function
    if (str_compare(captcha, userInput) == 0)
        printf("CAPTCHA Verified Successfully!\n");
    else
        printf("Incorrect CAPTCHA!\n");

    // Demonstrating string functions
    printf("\n--- String Function Demonstration ---\n");

    printf("Length of CAPTCHA: %d\n", str_length(captcha));

    char copied[20];
    str_copy(copied, captcha);
    printf("Copied CAPTCHA: %s\n", copied);

    char extra[] = "XYZ";
    str_concat(copied, extra);
    printf("After concatenation: %s\n", copied);

    return 0;
}
