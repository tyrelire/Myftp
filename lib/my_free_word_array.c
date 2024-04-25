/*
** EPITECH PROJECT, 2022
** str_to_word_array
** File description:
** my_get_nbr.c
*/
#include "../include/my.h"

int my_free_word_array(char **tab)
{
    if (tab == NULL)
        return 0;
    for (int k = 0; tab[k] != NULL; k++) {
        if (tab[k] == NULL)
            break;
        free(tab[k]);
    }
    free(tab);
    return 0;
}
