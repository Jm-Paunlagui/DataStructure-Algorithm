#include <stdio.h>
#include <cs50.c>
#include <math.h>
#include <ctype.h>

int main(void)
{
    int letters_count = 0, sentence_count = 0;
    float word_count = 1;

    char *text = get_string("","Text: "); // Getting the texts

    //Counting them all
    for (int txt = 0; text[txt] != 0x00; txt++)
    {
        // counts letters
        if (isalpha(text[txt]))
        {
            letters_count++;
        }

        // counts words
        else if (isspace(text[txt]))
        {
            word_count++;
        }

        // counts sentences
        else if (text[txt] == '.' || text[txt] == '!' || text[txt] == '?')
        {
            sentence_count++;
        }
    }
    int L = (100 * letters_count / word_count);
    float S = (100 * sentence_count / word_count);
    float grade = (0.0588 * L - 0.296 * S - 15.8); // the formula called Coleman-Liau index

    if (grade >= 16)
    {
        printf("Grade 16+\n");

    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.f\n", round(grade));
    }
}