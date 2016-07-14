/* Marcus Mallum */
/* Assignment 2 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void printAnswer(int keep[][50], /*const*/ char puzzle[][50], size_t size);
void findWord(int keep [][50], char puzzle[][50], char *word, size_t size);
int checkSides(int keep [][50], char puzzle[][50], char *word, size_t row, size_t column, size_t count, size_t size, size_t side);
int checkLeft(int keep [][50], char puzzle[][50], char *word, size_t row, size_t column, size_t count, size_t size);
int checkRight(int keep [][50], char puzzle[][50], char *word, size_t row, size_t column, size_t count, size_t size);
int checkDown(int keep [][50], char puzzle[][50], char *word, size_t row, size_t column, size_t count, size_t size);
int checkUp(int keep [][50], char puzzle[][50], char *word, size_t row, size_t column, size_t count, size_t size);
int checkLeftDown(int keep [][50], char puzzle[][50], char *word, size_t row, size_t column, size_t count, size_t size);
int checkLeftUp(int keep [][50], char puzzle[][50], char *word, size_t row, size_t column, size_t count, size_t size);
int checkRightDown(int keep [][50], char puzzle[][50], char *word, size_t row, size_t column, size_t count, size_t size);
int checkRightUp(int keep [][50], char puzzle[][50], char *word, size_t row, size_t column, size_t count, size_t size);

int main(void) {
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
        word = fgets(word, size + 2, stdin);
        if (word != NULL)
        {
/*            printf("%s", word);*/
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
    size_t side;
    for (row = 0; row < size; ++row)
    {
        for (column = 0; column < size; ++column)
        {
            for (side = 0; side < 8; ++side)
            {
                checkSides(keep, puzzle, word, row, column, 0, size, side);
            }
            /*printAnswer(keep, puzzle, size);*/
        }
    }
}

int checkSides(int keep [][50], char puzzle[][50], char *word, size_t row, size_t column, size_t count, size_t size, size_t side)
{
    static int (*sides[8])(int [][50], char [][50], char *, size_t, size_t, size_t, size_t) = { checkRight, checkLeft, checkDown, checkUp,
                                                                                                checkRightDown, checkRightUp, checkLeftDown, checkLeftUp};
    /* Word has been found */
    if(!isupper(word[count]))
    {
        return 1;
    }
    else if(row >= size || row < 0 || column < 0 || column >= size) /* if out of bounds */
    {
        return 0;
    }

    /*Does word letter = puzzle letter */
    if(word[count] == puzzle[row][column])
    {
        /* Check going different sides */
        if ((*sides[side])(keep, puzzle, word, row, column, count, size))
        {
            keep[row][column] = 1;
            return 1;
        }
    }
        return 0;
}

int checkRight(int keep [][50], char puzzle[][50], char *word, size_t row, size_t column, size_t count, size_t size)
{
    /* Check going right */
    return checkSides(keep, puzzle, word, row, column + 1, count + 1, size, 0);
}

int checkLeft(int keep [][50], char puzzle[][50], char *word, size_t row, size_t column, size_t count, size_t size)
{
    /* Check going left */
    return checkSides(keep, puzzle, word, row, column - 1, count + 1, size, 1);
}

int checkDown(int keep [][50], char puzzle[][50], char *word, size_t row, size_t column, size_t count, size_t size)
{
    /* Check going down */
    return checkSides(keep, puzzle, word, row + 1, column, count + 1, size, 2);
}

int checkUp(int keep [][50], char puzzle[][50], char *word, size_t row, size_t column, size_t count, size_t size)
{
    /* Check going up */
    return checkSides(keep, puzzle, word, row - 1, column, count + 1, size, 3);
}

int checkRightDown(int keep [][50], char puzzle[][50], char *word, size_t row, size_t column, size_t count, size_t size)
{
    /* Check going right and down */
    return checkSides(keep, puzzle, word, row + 1, column + 1, count + 1, size, 4);
}

int checkRightUp(int keep [][50], char puzzle[][50], char *word, size_t row, size_t column, size_t count, size_t size)
{
    /* Check going right and up */
    return checkSides(keep, puzzle, word, row - 1, column + 1, count + 1, size, 5);
}

int checkLeftDown(int keep [][50], char puzzle[][50], char *word, size_t row, size_t column, size_t count, size_t size)
{
    /* Check going left and down */
    return checkSides(keep, puzzle, word, row + 1, column - 1, count + 1, size, 6);
}

int checkLeftUp(int keep [][50], char puzzle[][50], char *word, size_t row, size_t column, size_t count, size_t size)
{
    /* Check going left and up */
    return checkSides(keep, puzzle, word, row - 1, column - 1, count + 1, size, 7);
}
