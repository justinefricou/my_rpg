/*
** EPITECH PROJECT, 2020
** tools_function
** File description:
** tools_function
*/

#include <stdlib.h>
#include <unistd.h>
#include "libmy.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strcmpp(char const *s1, char const *s2)
{
    int i = 0;

    while ((s1[i] != '\0') && (s2[i] != '\0') && (s1[i] == s2[i]))
        i++;
    if (s1[i] < s2[i])
        return (-1);
    else if (s2[i] < s1[i])
        return (1);
    else
        return (0);
}

char *my_len_str(char *str)
{
    char *len_str = NULL;
    int i = 0;

    if (str[0] == '\0')
        return (NULL);
    for (; str[i] != '\0'; i++);
    len_str = malloc(sizeof(char) * i);
    for (int j = 0; j != i - 1; j++) {
        if (str[j] != '\t')
            len_str[j] = str[j];
        else
            len_str[j] = ' ';
    }
    return (len_str);
}

int my_putnbr(int nb)
{
    if (nb < -2147483647 || nb > 2147483647)
        return (84);
    if (nb > 9)
        my_putnbr(nb / 10);
    if (nb < 0 && nb > -10) {
        my_putchar('-');
    } else if (nb < 0) {
        my_putchar('-');
        my_putnbr(nb / -10);
    }
    if (nb >= 0)
        my_putchar(nb % 10 + '0');
    if (nb < 0)
        my_putchar(- nb % 10 + '0');
    return (0);
}

int my_putstr(char const *str)
{
    if (str == NULL)
        return (84);
    write(1, str, my_strlen(str));
    return (0);
}