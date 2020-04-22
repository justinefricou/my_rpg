/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Loads player's infos : name, position, level and XPs.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/System/Vector2.h>
#include "libmy.h"
#include "general_data.h"
#include "save_load.h"

static char *get_player_name(FILE *save_file)
{
    char *line = NULL;
    char *new_name = NULL;
    int new_name_len = 0;
    int start = 0;

    line = get_line_from_save_file(save_file);
    if (!line)
        return (NULL);
    start = my_strlen("player_name ");
    new_name_len = my_strlen(line) - start;
    new_name = malloc(sizeof(char) * (new_name_len + 1));
    if (new_name) {
        for (int i = 0; i < new_name_len; i++)
            new_name[i] = line[i + start];
        new_name[new_name_len] = 0;
    }
    free(line);
    return (new_name);
}

int load_saved_player_name(general_data_t *data, FILE *save_file)
{
    char *new_name = NULL;

    new_name = get_player_name(save_file);
    if (!new_name) {
        write(2, "Error : player's name could not be loaded.\n", 43);
        return (84);
    }
    if (data->player.name)
        free(data->player.name);
    data->player.name = new_name;
    return (0);
}

int load_saved_player_position(sfVector2f *position, FILE *save_file)
{
    char *line = NULL;
    int start = 0;

    line = get_line_from_save_file(save_file);
    if (!line) {
        write(2, "Error : player's position could not be loaded.\n", 47);
        return (84);
    }
    start = my_strlen("player_position ");
    position->x = get_nbr_until(&(line[start]), ',');
    for (; line[start] && line[start] != ','; start++);
    position->y = get_nbr_until(&(line[start + 1]), 0);
    free(line);
    return (0);
}

int load_saved_player_lvl(player_t *player, FILE *save_file)
{
    char *line = NULL;
    int start = 0;

    line = get_line_from_save_file(save_file);
    if (!line) {
        write(2, "Error : player's level could not be loaded.\n", 44);
        return (84);
    }
    start = my_strlen("player_level ");
    player->level = get_nbr_until(&(line[start]), 0);
    free(line);
    return (0);
}

int load_saved_player_xp(player_t *player, FILE *save_file)
{
    char *line = NULL;
    int start = 0;

    line = get_line_from_save_file(save_file);
    if (!line) {
        write(2, "Error : player's xp could not be loaded.\n", 41);
        return (84);
    }
    start = my_strlen("player_xp ");
    player->xp.x = get_nbr_until(&(line[start]), 0);
    free(line);
    line = get_line_from_save_file(save_file);
    if (!line) {
        write(2, "Error : player's max xp could not be loaded.\n", 45);
        return (84);
    }
    start = my_strlen("player_max_xp ");
    player->xp.y = get_nbr_until(&(line[start]), 0);
    free(line);
    return (0);
}