/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** my_putstr
*/

#include <stdlib.h>
#include <unistd.h>
#include "libmy.h"

int find_nbr_lines(char *str, char c, int len)
{
    int in = 0;
    int lines = 1;

    for (int i = 0; i < len; i++) {
        if (str[i] != c && in != 1) {
            in = 1;
            lines++;
        }
        if (str[i] == c)
            in = 0;
    }
    return (lines);
}

char *find_word(char *str, char c, int len)
{
    static int start = 0;
    int temp = 0;
    int end = 0;
    char *word = NULL;

    for (; (str[start] == c) && (start < len); start++);
    for (end = start; str[end] != c && end < len; end++);
    temp = start;
    word = malloc(sizeof(char) * (end - temp + 1));
    if (word == NULL)
        return (NULL);
    for (int i = 0; i < end - start; i++)
        word[i] = str[start + i];
    start = end;
    return (word);
}

char **array_alloc(char **map, char *str, char c, int len)
{
    int lines = find_nbr_lines(str, c, len);

    map = malloc(sizeof(char *) * lines - 1);
    if (map == NULL)
        return (NULL);
    for (int i = 0; i < lines - 1; i++) {
        map[i] = find_word(str, c, len);
        if (map[i] == NULL)
            return (NULL);
    }
    map[lines - 1] = NULL;
    return (map);
}

char **str_to_array(char *str, char c)
{
    int len = my_strlen(str);
    char **map = NULL;

    map = array_alloc(map, str, c, len);
    return (map);
}