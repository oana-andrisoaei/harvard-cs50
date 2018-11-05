#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float n;
    do
    {
        printf("Please specify the change owed: ");
        n = get_float();
    }
    while (n < 0);

    int change = (int)(n * 100 + .5);

    int coins = 0;

    while (change - 25 >= 0)
    {
        change = change - 25;
        coins++;
    }

    while (change - 10 >= 0)
    {
        change = change - 10;
        coins++;
    }

    while (change - 5 >= 0)
    {
        change = change - 5;
        coins++;
    }

    while (change - 1 >= 0)
    {
        change = change - 1;
        coins++;
    }

    printf("%i\n", coins);
}