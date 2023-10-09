#include <stdio.h>

int main() {
    // Open the file in read mode
    FILE *file = fopen("files.txt", "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Initialize the counter for vowels
    int vowel_count = 0;

    // Read the file character by character
    char c;
    while ((c = fgetc(file)) != EOF) {
        // Check if the character is a vowel
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowel_count++;
        }
    }

    // Print the count of vowels
    printf("Number of vowels: %d\n", vowel_count);

    // Close the file
    fclose(file);

    return 0;
}
