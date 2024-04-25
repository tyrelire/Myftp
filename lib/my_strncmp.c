/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "../include/my.h"

int my_strncmp(char *str1, char *str2, int len)
{
    if (my_strlen(str1) < len)
        return 0;
    if (my_strlen(str2) < len)
        return 0;
    for (int i = 0; i != len; i++) {
        if (str1[i] != str2[i])
            return 0;
    }
    return 1;
}
