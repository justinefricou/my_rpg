/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Useful functions to save and load a game.
*/

#include <stdio.h>

int open_save_file(FILE **save_file, int save_nb, char *mode)
{
    char *filepath = "saves/0.save";

    filepath[6] = save_nb + '0';
    *save_file = fopen(filepath, mode);
    if (*save_file == NULL) {
        write(2, "Error : save file could not be opened.\n", 39);
        return (84);
    }
    return (0);
}