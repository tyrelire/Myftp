/*
** EPITECH PROJECT, 2022
** str_to_word_array
** File description:
** str_to_word_array.c
*/
#include "../include/my.h"

int cpt_col(char const *str)
{
    int cpt = 0;
    int k = 0;

    while (str[k] != '\n') {
        k++;
    }
    k++;
    while (str[k] != '\0' && str[k] != '\n') {
        cpt++;
        k++;
    }
    return cpt;
}

int cpt_lign(char const *str)
{
    int cpt = 0;

    for (int b = 0; str[b] != '\0'; b++) {
        if (str[b] == '\n') {
            cpt++;
        }
    }
    cpt = cpt + 1;
    return cpt - 1;
}

char **my_str_to_word_array(char const *str)
{
    int next = 0;
    int colonne = 0;
    int ligne = 0;
    char **tab = malloc(sizeof(char *) * (cpt_lign(str) + 1));

    while (colonne != cpt_lign(str)) {
        tab[colonne] = malloc(sizeof(char) * (cpt_col(str) + 1));
        while (str[next] != '\n' && str[next] != '\0') {
            tab[colonne][ligne] = str[next];
            next = next + 1;
            ligne = ligne + 1;
        }
        colonne = colonne + 1;
        next = next + 1;
        ligne = 0;
    }
    tab[colonne] = NULL;
    return tab;
}
