/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Saves the current progression.
*/

#include <stdio.h>
#include "save_load.h"

static int save_data(general_data_t *data, FILE *save_file)
{
    sfVector2f *position = NULL;

    save_player_name(data->player.name, save_file);
    save_player_lvl_and_xp(data->player, save_file);
    save_player_pv(data->player.pv, save_file);
    save_player_money(data->player, save_file);
    /*position = dg_entity_get_component(player, "pos"); // get player
    save_player_position(position, save_file);*/
    save_inventory(data->inventory, save_file);
    save_clues(data->clues, save_file);
    save_skills(data->skills, save_file);
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
    }
    return (return_value);
}