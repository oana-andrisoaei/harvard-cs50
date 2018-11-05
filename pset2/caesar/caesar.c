#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Please provide only the key as an argument\n");
        return 1;
    }

    int key = atoi(argv[1]);

    printf("plaintext:");
    string text = get_string();

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                text[i] = (text[i] + key - 'A') % 26 + 'A';
            }
            else
            {
                text[i] = (text[i] + key - 'a') % 26 + 'a';
            }
        }
    }

    printf("ciphertext:%s\n", text);
    return 0;
}