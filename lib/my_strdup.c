/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** my_strdup
*/

#include "../include/my.h"

char *my_strdup(char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));
    int x = 0;

    while (src[x] != '\0') {
        str[x] = src[x];
        x = x + 1;
    }
    str[x] = '\0';
    return (str);
}
