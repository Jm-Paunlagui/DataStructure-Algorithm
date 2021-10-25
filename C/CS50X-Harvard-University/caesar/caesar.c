#include <stdio.h>
#include <cs50.c>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Get key
    if (argc == 2 && isdigit(*argv[1]))
    {
        //conditions to check the validity of key
        if (argc == 2)
        {
            // conditions to check whether the given input is digit or not

            for (int i = 1; i < argc; i++)
            {
                for (int j = 0, n = strlen(argv[1]); j < n; j++)
                {
                    if (isalpha(argv[i][j]) || argv[1][0] == '-')
                    {

                        //condition for checking negative number and letters

                        printf("Usage: %s key\n", argv[0]);
                        return 1;
                    }
                }
            }
        }
        else
        {
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
        int key = atoi(argv[1]);

        //prompt user for input

        string text = get_string("","plaintext: ");

        int len = strlen(text);   //storing length of the input text

        printf("ciphertext: ");


        //loop to check each character of input text

        for (int l = 0; l < len; l++)
        {

            //checking uppercase letters

            if (isupper(text[l]))
            {
                //printing uppercase letters (ciphertext)
                printf("%c", (((text[l] - 'A') + key) % 26) + 'A');
            }
            //checking lowercase letters

            else if (islower(text[l]))
            {
                //printing lowercase letters (cyphertext)
                printf("%c", (((text[l] - 'a') + key) % 26) + 'a');
            }
            else
            {
                //printing charcters as it is if it is not alphabet
                printf("%c", text[l]);
            }
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

}
