/*
** EPITECH PROJECT, 2022
** binaire
** File description:
** binaire
*/
#include "../include/my.h"


unsigned int binaire(unsigned int number)
{
    unsigned int ptr = 0;
    unsigned int tab[32];

    while (number > 0) {
        tab[ptr] = number % 2;
        number = number / 2;
        ptr = ptr + 1;
    }
    for (int reverse = ptr - 1; reverse >= 0; reverse--) {
        my_put_nbr(tab[reverse]);
    }
    return 0;
}
