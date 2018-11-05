#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long long cc;
    do
    {
        printf("Please specify the credit card number: ");
        cc = get_long_long();
    }
    while (cc <= 0);

    bool isEven = false;
    int sum = 0, digits = 0, second = 0, first = 0;

    while (cc > 0)
    {
        if (isEven)
        {
            first = cc % 10;
            int multipled = first * 2;
            if (multipled >= 10)
            {
                sum += multipled % 10;
                multipled = multipled / 10;
            }
            sum += multipled % 10;
        }
        else
        {
            second = cc % 10;
            sum += second;
        }
        cc = cc / 10;
        isEven = !isEven;
        digits++;
    }

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (digits == 15 && second == 3 && (first == 4 || first == 7))
    {
        printf("AMEX\n");
    }
    else if (digits == 16 && first == 5 && (second > 0 && second < 6))
    {
        printf("MASTERCARD\n");
    }
    else if (digits >= 13 && digits <= 16 && first == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}