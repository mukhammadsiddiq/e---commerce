#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    FILE *file = fopen("text.txt", "a");

    if(file == NULL)
        return -1;
    int score = 0;
    while (true)
    {
        printf("Score: -1 for quit:"); // printing info for the user
        scanf("%d", &score); // scanning user input
        if(score == -1) break;
        else fprintf(file, "Score: %d\n", score); // adding a new score to the file 
    }
    fclose(file);
    return 0;
}