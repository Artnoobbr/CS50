// libraries
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height; // to solve the scope problem
    // If the user put a number other than between 1 and 8 it will just repeat
    // until the user put the right number
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    int row = 1; // important to check how many # should print
    for (int i = 0; i < height; i++)
    {

        // left side space
        for (int y = height - 1; y >= row; y--)
        {
            printf(" ");
        }

        // left side #
        for (int x = 0; x < row; x++)
        {
            printf("#");
        }

        // middle space
        for (int middle = 0; middle < 2; middle++)
        {
            printf(" ");
        }

        // right side #
        for (int z = 0; z < row; z++)
        {
            printf("#");
        }

        printf("\n");
        row += 1;
    }
}
