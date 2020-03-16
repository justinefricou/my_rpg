/*
** EPITECH PROJECT, 2019
** my_show_word_array
** File description:
** CPool Day08 Task03
*/

#include <stdlib.h>
#include "libmy.h"

void my_putarray(char **tab, char last_char)
{
    for (int i = 0; tab[i] != NULL && my_strlen(tab[i]) > 0; i++) {
        my_putstr(tab[i]);
        my_putchar(last_char);
    }
}