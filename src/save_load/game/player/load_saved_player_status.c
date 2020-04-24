/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Loads player's status : health points and money.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/System/Vector2.h>
#include "libmy.h"
#include "general_data.h"
#include "save_load.h"

int load_saved_player_pv(general_data_t *data, FILE *save_file)
{
    char *line = NULL;
    int start = 0;

    line = get_line_from_save_file(save_file);
    if (!line) {
        write(2, "Error : player's pv could not be loaded.\n", 41);
        return (84);
    }
    start = my_strlen("current_pv ");
    data->player.pv.x = get_nbr_until(&(line[start]), 0);
    free(line);
    line = get_line_from_save_file(save_file);
    if (!line) {
        write(2, "Error : player's max pv could not be loaded.\n", 45);
        return (84);
    }
    start = my_strlen("max_pv ");
    data->player.pv.y = get_nbr_until(&(line[start]), 0);
    free(line);
    return (0);
}

int load_saved_player_money(player_t *player, FILE *save_file)
{
    char *line = NULL;
    int start = 0;

    line = get_line_from_save_file(save_file);
    if (!line) {
        write(2, "Error : player's money could not be loaded.\n", 44);
        return (84);
    }
    start = my_strlen("player_level ");
    player->money = get_nbr_until(&(line[start]), 0);
    free(line);
    return (0);
}