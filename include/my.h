/*
** EPITECH PROJECT, 2024
** my
** File description:
** my.h
*/
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#ifndef MY_H_
    #define MY_H_

char *my_str_cut(char *str, int k);
int my_putchar_err(char c, int fd);
int my_fast_putstr(const char *s);
int my_strlen(char const *str);
int my_putstr_err(char const *str, int fd);
int my_putchar(char c);
char **my_str_to_word_array(char const *str);
char **my_str_to_word_array_space(char const *s);
int cpt_lign_space(char const *str);
int cpt_col_space(char const *str, int index);
int my_putstr(const char *s);
int my_free_word_array(char **tab);
int cpt_col(char const *str);
int cpt_lign(char const *str);
char *my_strcat(char *dest, char *src);
int my_put_tab(char **tab);
char *my_strcpy(char *d, char const *s);
unsigned int binaire(unsigned int number);
int decimal_to_octal(int number);
int into_hex_max(int number);
int into_hex_min(int number);
int my_putstr(char const *str);
unsigned int non_sign(unsigned int nb);
char *my_strdup(char const *src);
int my_strlen(char const *str);
int nprintable_char(char const *str);
int my_put_nbr(int nb);
int my_strncmp(char *str1, char *str2, int len);
int my_putchar(char c);
int my_put_tab(char **str);
ssize_t my_fastput_array(char **tab);
ssize_t my_fastput_array_v2(char **tab);
int my_get_nbr(const char *str);
int my_strncmp(char *str1, char *str2, int len);

#endif
