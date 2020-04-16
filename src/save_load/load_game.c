/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Loads a game.
*/

#include <stdio.h>
#include "save_load.h"

int load_saved_game(general_data_t *data, int save_nb)
{
    FILE *save_file = NULL;
    int return_value = 0;

    return_value = open_save_file(&save_file, save_nb, "r");
    if (return_value != 84) {
        return_value = load_saved_data(data, save_file);
        fclose(save_file);
    }
    return (return_value);
}

int load_saved_data(general_data_t *data, FILE *save_file)
{
    if (load_saved_player_name(data, save_file) == 84)
        return (84);
    // load other things
    return (0);
}