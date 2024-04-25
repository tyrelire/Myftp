/*
** EPITECH PROJECT, 2022
** intohexmin.c
** File description:
** intohexmin
*/
#include "../include/my.h"

int into_hex_min(int number)
{
    int hex[16];
    char *tab = "0123456789abcdef";
    int i = 0;

    for (i = 0; number > 0; i++) {
        hex[i] = number % 16;
        number = number / 16;
    }
    for (int j = i - 1; j >= 0; j--) {
        my_putchar(tab[hex[j]]);
    }
    return 0;
}
