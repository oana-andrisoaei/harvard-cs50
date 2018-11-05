#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Please provide only the hash password\n");
        return 1;
    }

    char *hash = argv[1];

    char salt[3];

    for (int i = 0; i < 2; i++)
    {
        salt[i] = hash[i];
    }

    salt[2] = '\0';

    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    char guess_1l[2];
    guess_1l[1] = '\0';
    for (int i = 0; i < strlen(characters); i++)
    {
        guess_1l[0] = characters[i];
        if (strcmp(crypt(guess_1l, salt), hash) == 0)
        {
            printf("%s\n", guess_1l);
            return 0;
        }
    }

    char guess_2l[3];
    guess_2l[2] = '\0';

    for (int i = 0; i < strlen(characters); i++)
    {
        guess_2l[0] = characters[i];
        for (int j = 0; j < strlen(characters); j++)
        {
            guess_2l[1] = characters[j];
            if (strcmp(crypt(guess_2l, salt), hash) == 0)
            {
                printf("%s\n", guess_2l);
                return 0;
            }
        }
    }

    char guess_3l[4];
    guess_3l[3] = '\0';

    for (int i = 0; i < strlen(characters); i++)
    {
        guess_3l[0] = characters[i];
        for (int j = 0; j < strlen(characters); j++)
        {
            guess_3l[1] = characters[j];

            for (int k = 0; k < strlen(characters); k++)
            {
                guess_3l[2] = characters[k];
                if (strcmp(crypt(guess_3l, salt), hash) == 0)
                {
                    printf("%s\n", guess_3l);
                    return 0;
                }
            }
        }
    }

    char guess_4l[5];
    guess_4l[4] = '\0';

    for (int i = 0; i < strlen(characters); i++)
    {
        guess_4l[0] = characters[i];
        for (int j = 0; j < strlen(characters); j++)
        {
            guess_4l[1] = characters[j];

            for (int k = 0; k < strlen(characters); k++)
            {
                guess_4l[2] = characters[k];

                for (int l = 0; l < strlen(characters); l++)
                {
                    guess_4l[3] = characters[l];

                    if (strcmp(crypt(guess_4l, salt), hash) == 0)
                    {
                        printf("%s\n", guess_4l);
                        return 0;
                    }
                }
            }
        }
    }

    char guess_5l[5];
    guess_5l[4] = '\0';

    for (int i = 0; i < strlen(characters); i++)
    {
        guess_5l[0] = characters[i];
        for (int j = 0; j < strlen(characters); j++)
        {
            guess_5l[1] = characters[j];

            for (int k = 0; k < strlen(characters); k++)
            {
                guess_5l[2] = characters[k];

                for (int l = 0; l < strlen(characters); l++)
                {
                    guess_5l[3] = characters[l];
                    for (int m = 0; m < strlen(characters); m++)
                    {
                        guess_5l[4] = characters[m];
                        if (strcmp(crypt(guess_5l, salt), hash) == 0)
                        {
                            printf("%s\n", guess_5l);
                            return 0;
                        }
                    }
                }
            }
        }
    }

    printf("Password not found.\n");
    return 0;
}