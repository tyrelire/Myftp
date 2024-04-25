/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** task02 day04
*/
#include "../include/my.h"

int my_putstr_err(char const *str, int fd)
{
    return write(fd, str, my_strlen(str));
}
