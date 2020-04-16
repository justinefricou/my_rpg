/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Saves the current progression.
*/

#include <stdio.h>
#include "save_load.h"

int save_game(general_data_t *data, int save_nb)
{
    FILE *save_file = NULL;
    int return_value = 0;

    return_value = open_save_file(&save_file, save_nb, "w");
    if (return_value != 84) {
        return_value = save_data(data, save_file);
        fclose(save_file);
    }
    return (return_value);
}

int save_data(general_data_t *data, FILE *save_file)
{
    save_player_name(data->player.name, save_file);
    save_player_pv(data->player.pv, save_file);
    // save other things
    return (0);
}