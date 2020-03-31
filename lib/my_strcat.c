/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** Concatenates two strings.
*/

#include <stdlib.h>
#include "libmy.h"

char *my_strcat(char *str1, char *str2)
{
    char *dest = NULL;
    int length1 = 0;
    int length2 = 0;

    for (; str1[length1]; length1++);
    for (; str2[length2]; length2++);
    dest = malloc(sizeof(char) * (length1 + length2 + 1));
    if (!dest)
        return (NULL);
    for (int i = 0; i < length1; i++)
        dest[i] = str1[i];
    for (int i = 0; i < length2; i++)
        dest[i + length1] = str2[i];
    dest[length1 + length2] = 0;
    return (dest);
}