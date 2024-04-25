/*
** EPITECH PROJECT, 2022
** my_str_cut.c
** File description:
** my_str_cut.c
*/

#include "../include/my.h"

char *my_str_cut(char *str, int k)
{
    int a = 0;
    int size = my_strlen(str);
    int strc = size - k;
    char *str2 = malloc(sizeof(char) * strc + 1);

    while (str[k] != '\0') {
        str2[a] = str[k];
        a = a + 1;
        k = k + 1;
    }
    str2[a] = '\0';
    return str2;
}
