/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Saves player's infos : name, etc.
*/

#include <stdio.h>
#include "libmy.h"

void save_player_name(char *name, FILE *save_file)
{
    int length = 0;

    for (; name[length]; length++);
    fwrite("player_name ", sizeof(char), 11, save_file);
    fwrite(name, sizeof(char), length, save_file);
    fwrite("\n", sizeof(char), 1, save_file);
}

void save_player_pv(int pv, FILE *save_file)
{
    char *str = NULL;
    int length = 0;

    str = my_itoa(pv);
    for (; str[length]; length++);
    fwrite("player_pv ", sizeof(char), 10, save_file);
    fwrite(str, sizeof(char), length, save_file);
    fwrite("\n", sizeof(char), 1, save_file);
}