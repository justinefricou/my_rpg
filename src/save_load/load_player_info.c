/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Loads player's infos : name, etc.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/System/Vector2.h>
#include "libmy.h"
#include "general_data.h"

static char *get_saved_player_name(FILE *save_file)
{
    char *new_name = NULL;
    int new_name_length = 0;
    char *line = NULL;
    ssize_t line_size = 0;

    line_size = getline(&line, 0, save_file);
    if (line_size == -1)
        return (NULL);
    new_name_length = line_size - 12 - (line[line_size - 1] == '\n');
    new_name = malloc(sizeof(char) * (new_name_length + 1));
    if (!new_name) {
        free(line);
        return (NULL);
    }
    for (int i = 0; i < new_name_length; i++)
        new_name[i] = line[i + 12];
    new_name[new_name_length] = 0;
    free(line);
    return (new_name);
}

int load_saved_player_name(general_data_t *data, FILE *save_file)
{
    char *new_name = NULL;

    if (data->player.name)
        free(data->player.name);
    new_name = get_saved_player_name(save_file);
    if (!new_name) {
        write(2, "Player's name could not be loaded.\n", 35);
        return (84);
    }
    data->player.name = new_name;
    return (0);
}

int load_saved_player_pv(general_data_t *data, FILE *save_file)
{
    char *line = NULL;
    ssize_t line_size = 0;

    line_size = getline(&line, 0, save_file);
    if (line_size == -1) {
        write(2, "Player's pv could not be loaded.\n", 33);
        return (84);
    }
    line[line_size - (line[line_size - 1 == '\n'])] = 0;
    data->player.pv = my_atoi(&(line[10]));
    free(line);
    return (0);
}

int load_saved_player_position(sfVector2f *position, FILE *save_file)
{
    char *line = NULL;
    ssize_t line_size = 0;
    int start = 0;

    line_size = getline(&line, 0, save_file);
    if (line_size == -1) {
        write(2, "Player's position could not be loaded.\n", 39);
        return (84);
    }
    line[line_size - (line[line_size - 1 == '\n'])] = 0;
    position->x = my_atoi(&(line[16]));
    for (int spaces = 0; line[start] && spaces < 2; start++)
        spaces += (line[start] == ' ');
    position->y = my_atoi(&(line[start]));
    free(line);
    return (0);
}