#include <stdio.h>
#include <unistd.h>

// in this program i prefer not to use printf(), just to make a challenge

// function for printing characters
void ft_putchar(char c)
{
    write(1, &c, 1);
}

// function to print out whole string
void ft_putstr(char *c)
{
    while(*c)
        ft_putchar(*c++);
}

int main(int argc, char **argv)
{
    FILE *f = fopen("text.txt", "r");
    if (f != NULL) //checks if file exists
    {
        char c;
        while ((c = fgetc(f)) != EOF) // "fgetc" will get the character from file and "EOF" "end of file"
            ft_putchar(c);
        fclose(f); // will close the file
    }else ft_putstr("File opening error\n");
}