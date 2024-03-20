#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card = get_long("Number: ");
    int counter = 1;

    int digit_sum = 0;
    int digit_sum2 = 0;
    int digit_total = 0;

    int first_number = 0;
    int firstTwo_numbers = 0;
    int last_number = card % 10;

    int digit;
    while (card != 0)
    {
        // First we will divide the card by 10!
        // So the % can get the other numbers
        card = card / 10;
        // printf("card divided by 10 = " "%li\n", card);

        // Now to get the digit we use the rest of a whole division by 10
        // So the output will be the last digit of the card
        digit = card % 10;
        // printf("digit of the card:" "%i \n", digit);

        if (card < 100 && card > 10)
        {
            firstTwo_numbers = card;
            first_number = card / 10;
        }

        counter++;

        // Now using a counter we will get the number’s second-to-last digit
        if (counter % 2 == 0)
        {
            digit = digit * 2;
            if (digit > 9)
            {
                int double_digit = digit % 10;
                digit = digit / 10;
                digit = digit % 10;

                digit = double_digit + digit;
                // printf("double digit amount: \n" "%i\n", digit);
            }
            // printf("%i \n", digit);
            digit_sum += digit;
            // printf("Soma total dos numeros 2:\n" "%i \n", digit_sum);
        }
        else
        {
            digit_sum2 += digit;
            // printf("Numéro não pulando 2 total:\n" "%i\n", digit_sum2);
        }

        digit_total = digit_sum + digit_sum2 + last_number;
        // printf("Total: " "%i \n", digit_total);

        // printf("%ld \n", card);
    }

    // printf("lenght: " "%i\n", counter);

    // Now after the loop is done we check if the
    // last digit of the total is 0!
    if (digit_total % 10 == 0)
    {
        int lenght = counter - 1; // Just to not have confusion

        // Check for firstnumber and lenght of the card
        if (lenght == 13 && first_number == 4)
        {
            printf("VISA\n");
        }
        else if (lenght == 15 && (firstTwo_numbers == 34 || firstTwo_numbers == 37))
        {
            printf("AMEX\n");
        }
        else if (lenght == 16)
        {
            // The visa and MasterCard can be 16 long
            // So now we need to check the start number
            if (first_number == 4)
            {
                printf("VISA\n");
            }
            else if (firstTwo_numbers == 51 || firstTwo_numbers == 52 || firstTwo_numbers == 53 ||
                     firstTwo_numbers == 54 || firstTwo_numbers == 55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
