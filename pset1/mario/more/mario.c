#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        printf("Please specify the height of the pyramid: ");
        n = get_int();
    }
    while (n < 0 || n > 23);

    int blocks = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - blocks; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < blocks; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int k = 0; k < blocks; k++)
        {
            printf("#");
        }
        printf("\n");
        blocks++;
    }
}