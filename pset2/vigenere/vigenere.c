#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    //Validate the user input
    if (argc != 2)
    {
        printf("Please provide only the string key as an argument\n");
        return 1;
    }

    //Parse the keyword
    string keyword = argv[1];
    int numberOfChars = strlen(keyword);
    int keys[numberOfChars];
    for (int i = 0; i < numberOfChars; i++)
    {
        if (isalpha(keyword[i]))
        {
            if (isupper(keyword[i]))
            {
                keys[i] = keyword[i] - 'A';
            }
            else
            {
                keys[i] = keyword[i] - 'a';
            }
        }
        else
        {
            printf("Please provide only letters as an argument\n");
            return 1;
        }
    }

    //Ask for the plaintext
    printf("plaintext:");
    string text = get_string();

    int j = 0;
    //Encrypt the plaintext
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                text[i] = (text[i] + keys[j % numberOfChars] - 'A') % 26 + 'A';
            }
            else
            {
                text[i] = (text[i] + keys[j % numberOfChars] - 'a') % 26 + 'a';
            }
            j++;
        }
    }

    printf("ciphertext:%s\n", text);
    return 0;
}