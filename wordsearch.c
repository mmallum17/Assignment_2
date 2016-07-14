/* Marcus Mallum */
/* Assignment 2 */
#include <stdio.h>
#include <ctype.h>

void printAnswer(int keep[][50], /*const*/ char puzzle[][50], size_t size);
void findWord(int keep [][50], char puzzle[][50], char *word, size_t size);
int checkLeft(int keep [][50], char puzzle[][50], char *word, int row, int column, int count, size_t size);
int checkRight(int keep [][50], char puzzle[][50], char *word, int row, int column, int count, size_t size);
int checkDown(int keep [][50], char puzzle[][50], char *word, int row, int column, int count, size_t size);
int checkUp(int keep [][50], char puzzle[][50], char *word, int row, int column, int count, size_t size);
int checkLeftDown(int keep [][50], char puzzle[][50], char *word, int row, int column, int count, size_t size);
int checkLeftUp(int keep [][50], char puzzle[][50], char *word, int row, int column, int count, size_t size);
int checkRightDown(int keep [][50], char puzzle[][50], char *word, int row, int column, int count, size_t size);
int checkRightUp(int keep [][50], char puzzle[][50], char *word, int row, int column, int count, size_t size);

int main(void)
{
    char puzzle[50][50];
    size_t size = 0;
    size_t row = 0;
    size_t column = 0;
    char letter;
    char *word;
    int keep[50][50] = {0};

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

    /* Print Solved Word Search */
    printAnswer(keep, puzzle, size);

    /* Read in Words */
    do
    {
        word = fgets(word,size, stdin);
        if (word != NULL)
        {
            printf("%s", word);
            for (row = 0; row < size; ++row)
            {
                for (column = 0; column < size; ++column)
                {
                    findWord(keep, puzzle, word, size);

                }
            }
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
            if(keep[row][column] == 1)
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
    int row;
    int column;
    for (row = 0; row < size; ++row)
    {
        for (column = 0; column < size; ++column)
        {
            checkRight(keep, puzzle, word, row, column, 0, size);
            checkLeft(keep, puzzle, word, row, column, 0, size);
            checkDown(keep, puzzle, word, row, column, 0, size);
            checkUp(keep, puzzle, word, row, column, 0, size);
            checkRightDown(keep, puzzle, word, row, column, 0, size);
            checkRightUp(keep, puzzle, word, row, column, 0, size);
            checkLeftDown(keep, puzzle, word, row, column, 0, size);
            checkLeftUp(keep, puzzle, word, row, column, 0, size);
        }
    }
}

int checkRight(int keep [][50], char puzzle[][50], char *word, int row, int column, int count, size_t size)
{
    if(word[count] == '/0')
    {
        return 1;
    }
    else if(row >= size || row < 0 || column < 0 || column >= size) /* if out of bounds */
    {
        return 0;
    }

    if(word[count] == puzzle[row][column])
    {
        /* Check going right */
        if (checkLeft(keep, puzzle, word, row, column + 1, count + 1, size))
        {
            keep[row][column] = 1;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
int checkLeft(int keep [][50], char puzzle[][50], char *word, int row, int column, int count, size_t size)
{
    if(word[count] == '/0')
    {
        return 1;
    }
    else if(row >= size || row < 0 || column < 0 || column >= size) /* if out of bounds */
    {
        return 0;
    }

    if(word[count] == puzzle[row][column])
    {
        /* Check going left */
        if (checkLeft(keep, puzzle, word, row, column - 1, count + 1, size))
        {
            keep[row][column] = 1;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
int checkDown(int keep [][50], char puzzle[][50], char *word, int row, int column, int count, size_t size)
{
    if(word[count] == '/0')
    {
        return 1;
    }
    else if(row >= size || row < 0 || column < 0 || column >= size) /* if out of bounds */
    {
        return 0;
    }

    if(word[count] == puzzle[row][column])
    {
        /* Check going down */
        if (checkLeft(keep, puzzle, word, row - 1, column, count + 1, size))
        {
            keep[row][column] = 1;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
int checkUp(int keep [][50], char puzzle[][50], char *word, int row, int column, int count, size_t size)
{
    if(word[count] == '/0')
    {
        return 1;
    }
    else if(row >= size || row < 0 || column < 0 || column >= size) /* if out of bounds */
    {
        return 0;
    }

    if(word[count] == puzzle[row][column])
    {
        /* Check going up */
        if (checkLeft(keep, puzzle, word, row + 1, column, count + 1, size))
        {
            keep[row][column] = 1;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
int checkRightDown(int keep [][50], char puzzle[][50], char *word, int row, int column, int count, size_t size)
{
    if(word[count] == '/0')
    {
        return 1;
    }
    else if(row >= size || row < 0 || column < 0 || column >= size) /* if out of bounds */
    {
        return 0;
    }

    if(word[count] == puzzle[row][column])
    {
        /* Check going right and down */
        if (checkLeft(keep, puzzle, word, row - 1, column + 1, count + 1, size))
        {
            keep[row][column] = 1;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
int checkRightUp(int keep [][50], char puzzle[][50], char *word, int row, int column, int count, size_t size)
{
    if(word[count] == '/0')
    {
        return 1;
    }
    else if(row >= size || row < 0 || column < 0 || column >= size) /* if out of bounds */
    {
        return 0;
    }

    if(word[count] == puzzle[row][column])
    {
        /* Check going right and up */
        if (checkLeft(keep, puzzle, word, row + 1, column + 1, count + 1, size))
        {
            keep[row][column] = 1;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
int checkLeftDown(int keep [][50], char puzzle[][50], char *word, int row, int column, int count, size_t size)
{
    if(word[count] == '/0')
    {
        return 1;
    }
    else if(row >= size || row < 0 || column < 0 || column >= size) /* if out of bounds */
    {
        return 0;
    }

    if(word[count] == puzzle[row][column])
    {
        /* Check going left and down */
        if (checkLeft(keep, puzzle, word, row - 1, column - 1, count + 1, size))
        {
            keep[row][column] = 1;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
int checkLeftUp(int keep [][50], char puzzle[][50], char *word, int row, int column, int count, size_t size)
{
    if(word[count] == '/0')
    {
        return 1;
    }
    else if(row >= size || row < 0 || column < 0 || column >= size) /* if out of bounds */
    {
        return 0;
    }

    if(word[count] == puzzle[row][column])
    {
        /* Check going left and up */
        if (checkLeft(keep, puzzle, word, row + 1, column - 1, count + 1, size))
        {
            keep[row][column] = 1;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}