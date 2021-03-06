/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Useful functions to save and load a game.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libmy.h"
#include "save_load.h"

int open_save_file(FILE **save_file, int save_nb, char *mode)
{
    char filepath[13] = {'s', 'a', 'v', 'e', 's', '/', '0', '.', 's', 'a',
                        'v', 'e', 0};
    char *filepath_options = "saves/options.save";

    if (save_nb == -1)
        *save_file = fopen(filepath_options, mode);
    else {
        filepath[6] = save_nb + '0';
        *save_file = fopen(filepath, mode);
    }
    if (*save_file == NULL)
        return (84);
    return (0);
}

int write_int_in_save_file(int nbr, FILE *save_file)
{
    char *str = NULL;

    str = my_itoa(nbr);
    if (!str)
        return (84);
    write_str_in_save_file(str, save_file);
    free(str);
}

int write_str_in_save_file(char *str, FILE *save_file)
{
    int length = 0;

    if (!str)
        return (84);
    for (; str[length]; length++);
    fwrite(str, sizeof(char), length, save_file);
    return (0);
}

char *get_line_from_save_file(FILE *save_file)
{
    char *line = NULL;
    ssize_t line_size = 0;
    size_t n = 0;

    line_size = getline(&line, &n, save_file);
    if (line_size == -1) {
        write(2, "Error : line could not be read.\n", 32);
        return (NULL);
    }
    if (line[line_size - 1] == '\n')
        line[line_size - 1] = 0;
    return (line);
}

int get_nbr_until(char *str, char end)
{
    int nbr = 0;
    int i = 0;

    for (; str[i] == '-' || str[i] == '+' || str[i] == '0'; i++);
    for (; str[i] != end && str[i] != 0; i++)
        nbr = nbr * 10 + (str[i] - 48);
    if (str[0] == '-')
        nbr = nbr * (-1);
    return (nbr);
}