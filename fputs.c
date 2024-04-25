#include <stdio.h>

int main(int argc, char **argv) {
    FILE *file = fopen("text.txt", "w");

    fputs("string", file);
    fclose(file);
}