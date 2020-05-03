/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Saves the current progression.
*/

#include <stdio.h>
#include <unistd.h>
#include "save_load.h"

static int save_data(general_data_t *data, FILE *save_file)
{
    sfVector2f *position = NULL;

    save_player_name(data->player.name, save_file);
    save_player_lvl_and_xp(data->player, save_file);
    save_player_pv(data->player.pv, save_file);
    save_player_pm(data->player.pm, save_file);
    save_player_money(data->player, save_file);
    save_inventory(data->inventory, save_file);
    save_clues(data->clues, save_file);
    save_event_vars(data->event_manager, save_file);
    return (0);
}

int save_game(general_data_t *data, int save_nb)
{
    FILE *save_file = NULL;
    int return_value = 0;

    return_value = open_save_file(&save_file, save_nb, "w");
    if (return_value != 84) {
        return_value = save_data(data, save_file);
        fclose(save_file);
    } else
        write(2, "Error : Save file could not be opened.\n", 39);
    return (return_value);
}