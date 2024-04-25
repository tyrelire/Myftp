/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** my_strcpy
*/
#include "../include/my.h"

char *my_strcpy(char *d, char const *s)
{
    int k = 0;

    for (k = 0; s[k] != '\0'; k++) {
        d[k] = s[k];
    }
    d[k] = '\0';
    return d;
}
