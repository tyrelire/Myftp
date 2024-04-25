/*
** EPITECH PROJECT, 2022
** my_fast_putstr
** File description:
** task02 day04
*/
#include "../include/my.h"

int my_fast_putstr(const char *s)
{
    if (!s) {
        return -1;
    return write(1, s, my_strlen(s));
    }
    return 0;
}
