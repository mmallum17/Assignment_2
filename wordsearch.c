/* Marcus Mallum */
/* Assignment 2 */
#include <stdio.h>
#include <ctype.h>

void printAnswer(const char puzzle[][50], size_t size);

int main(void)
{
    char puzzle[50][50];
    size_t size = 0;
    size_t row = 0;
    size_t column = 0;
    char letter;

    /* Read in Word Search */
    do
    {
        column = 0;
        size = 0;
        do
        {
            letter = getchar();
            if(!(isspace(letter)))
            {
                puzzle[row][column++] = letter;
                size++;
            }
        }while(letter != '\n');
        row++;
    }while(row < size);
    printAnswer(puzzle, size);
    return 0;
}

void printAnswer(const char puzzle[][50], size_t size)
{
    size_t row;
    size_t column;
    puts("");
    puts("");
    for(row = 0; row < size; ++row)
    {
        for (column = 0; column < size; ++column)
        {
            printf("%c ", puzzle[row][column]);
        }
        puts("");
    }
}