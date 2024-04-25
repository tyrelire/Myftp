/*
** EPITECH PROJECT, 2022
** nonsign.c
** File description:
** nonsign
*/
#include "../include/my.h"

unsigned int non_sign(unsigned int nb)
{
    if (nb <= 9) {
        my_putchar(nb + 48);
    } else if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    return 0;
}
