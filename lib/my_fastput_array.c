/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** task02 day04
*/
#include "../include/my.h"

ssize_t my_fastput_array(char **tab)
{
    char back = '\n';
    ssize_t account = 0;
    size_t k = 1;

    if (!tab) {
        return -1;
    }
    while (tab[k]) {
        account += write(1, tab[k], my_strlen(tab[k]));
        account += write(1, &back, 1);
        k++;
    }
    return 0;
}

ssize_t my_fastput_array_v2(char **tab)
{
    char back = '\n';
    ssize_t account = 0;
    size_t k = 0;

    if (!tab) {
        return -1;
    }
    while (tab[k]) {
        account += write(1, tab[k], my_strlen(tab[k]));
        account += write(1, &back, 1);
        k++;
    }
    return 0;
}
