/*
** EPITECH PROJECT, 2019
** my_strcpy.c
** File description:
** Copies a string to another
*/

#include <stdlib.h>
#include "libmy.h"

char *my_strcpy(char *dest, char *src)
{
    int z = 0;

    if (dest == NULL || src == NULL)
        return (NULL);
    for (; src[z] != '\0'; z++)
        dest[z] = src[z];
    dest[z] = '\0';
    return (dest);
}