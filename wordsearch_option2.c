/* Marcus Mallum */
/* Assignment 2 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void printAnswer(int keep[][50], char puzzle[][50], size_t size);
void findWord(int keep[][50], char puzzle[][50], char *word, size_t size);
int checkSides(int keep[][50], char puzzle[][50], char *word, size_t size, size_t row, size_t column, size_t position, int deltaRow, int deltaColumn);

int main(void)
{
    char puzzle[50][50];
    size_t size;
    size_t row = 0;
    size_t column = 0;
    char letter;
    char *word;
    int keep[50][50] = {{0}};

    /* Read in Word Search Grid */
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

    /* Read in Words */
    do
    {
        word = fgets(word, sizeof(char) * (size + 2), stdin);
        if (word != NULL)
        {
            findWord(keep, puzzle, word, size);
        }
    }while(word != NULL);

    /* Print Solved Word Search */
    printAnswer(keep, puzzle, size);

    return 0;
}

void printAnswer(int keep [][50],/*const*/ char puzzle[][50], size_t size)
{
    size_t row;
    size_t column;
    for(row = 0; row < size; ++row)
    {
        for (column = 0; column < size; ++column)
        {
            if(keep[row][column])
            {
                printf("%c ", puzzle[row][column]);
            }
            else
            {
                printf("%s", "  ");
            }
        }
        puts("");
    }
}

void findWord(int keep [][50], char puzzle[][50], char *word, size_t size)
{
    size_t row;
    size_t column;
    size_t direction;
    int deltaRow;
    int deltaColumn;
    for(row = 0; row < size; ++row)
    {
        for (column = 0; column < size; ++column)
        {
            for (direction = 0; direction <= 8; ++direction)
            {
                deltaRow = direction / 3 - 1;
                deltaColumn = direction % 3 - 1;
                if (deltaRow != 0 || deltaColumn != 0)
                {
                    checkSides(keep, puzzle, word, size, row, column, 0, deltaRow, deltaColumn);
                }
            }
        }
    }
}

int checkSides(int keep [][50], char puzzle[][50], char *word, size_t size, size_t row, size_t column, size_t position, int deltaRow, int deltaColumn)
{
    /* Word has been found */
    if(word[position] == '\n')
    {
        return 1;
    }
    else if(row >= size || row < 0 || column < 0 || column >= size) /* if out of bounds */
    {
        return 0;
    }

    /* Does letter in word = letter in puzzle */
    if(word[position] == puzzle[row][column])
    {
        /* Check going different sides */
        if (checkSides(keep, puzzle, word, size, row + deltaRow, column + deltaColumn, position + 1, deltaRow, deltaColumn))
        {
            keep[row][column] = 1;
            return 1;
        }
    }
    return 0;
}