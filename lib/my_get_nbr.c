/*
** EPITECH PROJECT, 2022
** str_to_word_array
** File description:
** my_get_nbr.c
*/
#include "../include/my.h"

int my_get_nbr(const char *str)
{
    int res = 0;
    int k = 0;

    while (str[k] != '\0') {
        if (str[k] >= 48 && str[k] <= 57) {
            res = res * (10) + str[k] - 48;
        }
    k++;
    }
    return res;
}
