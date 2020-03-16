/*
** EPITECH PROJECT, 2019
** libfae
** File description:
** Return a number from a string (int)
*/

#include <stdlib.h>
#include "libmy.h"

char *my_itoa(int nb)
{
    char *str = malloc(sizeof(char) * 12);
    int i = (nb < 0 ? 1 : 0) + my_nblen(nb) - 1;

    for (int y = 0; y < 12; y++)
        str[y] = '\0';
    str[0] = (nb < 0) ? '-' : '\0';
    if (nb == 0)
        str[0] = '0';
    for (; nb != 0; i--) {
        str[i] = (nb % 10) + '0';
        nb /= 10;
    }
    return str;
}