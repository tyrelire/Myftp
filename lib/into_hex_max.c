/*
** EPITECH PROJECT, 2022
** intohexmax.c
** File description:
** intohexmax
*/
#include "../include/my.h"

int into_hex_max(int number)
{
    int hex[16];
    char *tab = "0123456789ABCDEF";
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
