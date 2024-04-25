/*
** EPITECH PROJECT, 2022
** str_to_word_array
** File description:
** str_to_word_array.c
*/
#include "../include/my.h"

int cpt_col_space(char const *s, int index)
{
    int k = 0;

    while (s[k + index] && s[k + index] != ' ' && s[k + index] != '\n') {
        k++;
    }
    return k;
}

void help_lign(char const *s, int *b, int *k)
{
    while (s[*b] == ' ' || s[*b] == '\n' || s[*b] == '\t') {
        *k = 1;
        *b = *b + 1;
    }
}

int cpt_lign_space(char const *s)
{
    int cpt = 1;
    int k = 0;
    int l = my_strlen(s);

    if (s[0] == '\0')
        return 0;
    for (int b = 0; s[b] != '\0'; b++) {
        k = 0;
        if (s[b] == ' ' || s[b] == '\n' || s[b] == '\t') {
            cpt++;
            help_lign(s, &b, &k);
        }
        if (k == 1)
            b = b - 1;
    }
    if (s[0] == ' ' || s[0] == '\n' || s[0] == '\t')
        cpt--;
    if (l && (s[l - 1] == ' ' || s[l - 1] == '\n' || s[l - 1] == '\t'))
        cpt--;
    return cpt;
}

char **my_str_to_word_array_space(char const *s)
{
    int is = 0;
    int i_tab = 0;
    int col = 0;
    char **tab = malloc(sizeof(char *) * (cpt_lign_space(s) + 1));

    while (i_tab < cpt_lign_space(s)) {
        while (s[is] == '\n' || s[is] == ' ' || s[is] == '\t')
            is++;
        tab[i_tab] = malloc(sizeof(char) * (cpt_col_space(s, is) + 1));
        while (s[is] && s[is] != ' ' && s[is] != '\n' && s[is] != '\t') {
            tab[i_tab][col] = s[is];
            is++;
            col++;
        }
        tab[i_tab][col] = '\0';
        i_tab++;
        col = 0;
    }
    tab[i_tab] = NULL;
    return tab;
}
