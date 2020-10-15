#include <stdio.h>
#include <cs50.c>

int main(void)
{
    int height, row;
    do
    {
        height = get_int("","Height: ");
    }
    while (height <= 0 || height > 8);

    for (row = 1; row <= height; row++)
    {
        for (int j = height; j > row; j--) //print spaces for left pyramid  ** spaces = current_row - height
        {
            printf(" ");
        }
        for (int k = 0; k < row; k++) // print hashes to left pyramid
        {
            printf("#");
        }
        printf("  ");
        for (int k = 0; k < row; k++) // print hashes to right pyramid
        {
            printf("#");
        }
        printf("\n"); // new line after each row
    }
}