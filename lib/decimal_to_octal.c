/*
** EPITECH PROJECT, 2022
** decimaltooctal
** File description:
** decimaltooctal
*/
#include "../include/my.h"


int decimal_to_octal(int number)
{
    int octal[10];
    int i = 0;
    int j = 0;

    for (i = 0; number > 0; i++) {
        octal[i] = number % 8;
        number = number / 8;
    }
    for (j = i - 1; j >= 0; j--) {
        my_put_nbr(octal[j]);
    }
    return 0;
}
