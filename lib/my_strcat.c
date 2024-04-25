/*
** EPITECH PROJECT, 2022
** my_put_tab.c
** File description:
** my_put_tab.c
*/
#include "../include/my.h"

char *my_strcat(char *dest, char *src)
{
    int j = 0;
    int i = 0;
    char *tmp = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    while (dest[i]) {
        tmp[i] = dest[i];
        i++;
    }
    while (src[j] != '\0') {
        tmp[i + j] = src[j];
        j++;
    }
    tmp[i + j] = '\0';
    return tmp;
}
