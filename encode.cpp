#include "headers.hpp"

// Given a number, it transforms the number as following:

//     it must take each digit and add an increment value.
//     The new number is encoded using the new digits in reverse order.

// if adding the increment the resulting number is greater than 9, it will have
// to be transformed into its corresponding one digit number: number 10 becomes
// 1, 11 becomes 2 and so on.

int compute_number_of_digits(int number)
{
    return number > 9 ? (number % 10) + 1 : number;
}

// number encoding (see description)
//
int encode(int number, int incr)
{
    int number_en = 0;
    if (number < 10)
        return compute_number_of_digits(number + incr);
    while (number != 0)
    {
        int unit = number % 10;
        number_en = number_en * 10 + compute_number_of_digits(unit + incr);
        number /= 10;
    }
    return number_en;
}
int main()
{
    printf("%d\n", encode(0, 3));
    return 0;
}
