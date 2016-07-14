/* Marcus Mallum */
/* Assignment 2 */
#include <stdio.h>

void printAnswer(const char puzzle[][size], size_t size);

int main(void)
{
    char puzzle[0][0];
    size_t size;

    /* Read in Word Search */

    printAnswer(puzzle, size);
    return 0;
}

void printAnswer(const char puzzle[][size], size_t size)
{
    size_t row;
    size_t column;
    for(row = 0; row < size; ++row)
    {
        for (column = 0; column < size; ++column)
        {
            printf("%c ", puzzle[row][column]);
        }
        puts("");
    }
}