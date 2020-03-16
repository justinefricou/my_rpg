/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** my_revstr
*/
#include "libmy.h"

char my_compt(char *str)
{
    char i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_revstr(char *str)
{
    char save = 0;
    char a = my_compt(str) - 1;
    char b = 0;

    while (b < a) {
        save = str[b];
        str[b] = str[a];
        str[a] = save;
        b++;
        a--;
    }
    return (str);
}