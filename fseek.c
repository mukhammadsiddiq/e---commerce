#include <stdio.h>

int main(int argc, char **argv)
{
    // Open the file "test.txt" in write mode ("w")
    FILE *file = fopen("test.txt", "w");

    // Write two lines of text to the file
    fprintf(file, "0123456789\n");
    fprintf(file, "abcdefghij\n");

    // Move the file position indicator to the beginning of the file
    fseek(file, 0, SEEK_SET);
    // Write "ABCD" at the beginning of the file, overwriting the existing content
    fprintf(file, "ABCD");

    // Move the file position indicator 5 characters forward from the current position
    fseek(file, 5, SEEK_CUR);
    // Write "Q" at the current position, effectively overwriting the character "5"
    fprintf(file, "Q");

    // Close the file
    fclose(file);

    // The file "test.txt" now contains:
    // ABCD45678Q
    // abcdefghij

    return 0;
}
