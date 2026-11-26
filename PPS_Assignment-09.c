#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *destFile;
    char sourcePath[100], destPath[100];
    int ch;

    // Get file paths from the user
    printf("Enter source file path: ");
    scanf("%99s", sourcePath);

    printf("Enter destination file path: ");
    scanf("%99s", destPath);

    // Open source file in read mode
    sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        perror("Error opening source file");
        return EXIT_FAILURE;
    }

    // Open destination file in write mode
    destFile = fopen(destPath, "w");
    if (destFile == NULL) {
        perror("Error opening destination file");
        fclose(sourceFile); // Close the already opened source file
        return EXIT_FAILURE;
    }

    // Copy contents character by character until End-Of-File (EOF)
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("File copied successfully.\n");

    // Close both files to flush buffers and free resources
    fclose(sourceFile);
    fclose(destFile);

    return 0;
}