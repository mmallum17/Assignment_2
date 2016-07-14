/* Marcus Mallum */
/* Assignment 2 */
#include <stdio.h>
#include <ctype.h>

void printAnswer(/*const*/ char puzzle[][50], size_t size);
void findWord(char puzzle[][50], char *word);

int main(void)
{
    char puzzle[50][50];
    size_t size = 0;
    size_t row = 0;
    size_t column = 0;
    char letter;
    char *word;

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
    printAnswer(puzzle, size);

    /* Read in Words */
    do
    {
        word = fgets(word,size, stdin);
        if (word != NULL)
        {
            printf("%s", word);
            findWord(puzzle, word);
        }
    }while(word != NULL);

    /* Print Solved Word Search */
    printAnswer(puzzle, size);
    return 0;
}

void printAnswer(/*const*/ char puzzle[][50], size_t size)
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

void findWord(char puzzle[][50], char *word)
{

}
