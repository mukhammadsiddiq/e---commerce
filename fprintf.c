#include <stdio.h>

int main(int argc, char **argv)
{
    FILE *file = fopen("text.txt", "w");

    if (file == NULL)
    {
        printf("Error opening file \n");
        return 1;
    }
    /* The fprintf function in C is used to write
    formatted data to a file. It is similar to printf,
    but instead of writing output to the console (standard output),
    it writes the output to the specified file stream. */

    fprintf(file, "text here\n");
    fprintf(file, "text there\n");
    // for int as usual '%i'
    int i = 65;
    fprintf(file, "%i\n", i);
    // for char as usual '%c'
    char t = 't';
    fprintf(file, "%c\n", t);
    // for both float an double as usual '%f'
    float f = 1.535;
    double d = 1.32;
    fprintf(file, "%f\n%f\n", f,d);
    fclose(file);  
}