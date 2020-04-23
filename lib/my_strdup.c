/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "libmy.h"

char *my_strdup(char *src)
{
    int src_len = my_strlen(src);
    char *res = malloc((src_len + 1) * sizeof(char));
    my_strcpy(res, src);
    return (res);
}