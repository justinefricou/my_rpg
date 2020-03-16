/*
** EPITECH PROJECT, 2020
** transform_character
** File description:
** transform_character
*/

#include "libmy.h"

int my_atoi(char *str)
{
    int longueur = my_strlen(str);
    int result = 0;

    for (int i = 0; i < longueur && longueur < 9; ++i)
        if (str[i] >= '0' && str[i] <= '9') {
            result += str[i] - '0';
            result *= 10;
        }
    return (result /= 10);
}

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}