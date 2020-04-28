/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Sets the save's infos (player's name and level) to be displayed on the slots.
*/

#include <stdlib.h>
#include <unistd.h>
#include "libmy.h"
#include "save_load.h"

static char *get_save_level(FILE *save_file)
{
    char *line = NULL;
    char *level = 0;
    int len = 0;
    int start = 0;

    line = get_line_from_save_file(save_file);
    if (!line)
        return (NULL);
    start = my_strlen("player_level ");
    for (len = start; line[len] && '0' <= line[len] && line[len] <= '9'; len++);
    len -= start;
    level = malloc(sizeof(char) * (len + 1));
    if (level) {
        for (int i = 0; i < len; i++)
            level[i] = line[i + start];
        level[len] = 0;
    }
    free(line);
    return (level);
}

static void set_save_name(sfText *name_txt, FILE *save_file)
{
    char *name = NULL;

    name = get_player_name(save_file);
    if (name)
        sfText_setString(name_txt, name);
}

static void set_save_level(sfText *level_txt, FILE *save_file)
{
    char *level = NULL;

    level = get_save_level(save_file);
    if (level)
        sfText_setString(level_txt, level);
}

int set_save_infos(sfText *name_txt, sfText *level_txt, int save_nb)
{
    FILE *save_file = NULL;
    int return_value = 0;

    if (open_save_file(&save_file, save_nb, "r") == 84)
        return (84);
    set_save_name(name_txt, save_file);
    set_save_level(level_txt, save_file);
    fclose(save_file);
    return (0);
}

int get_save_infos(char **default_name, char **default_level, int save_nb)
{
    FILE *save_file = NULL;
    char *name = NULL;
    char *level = NULL;

    if (open_save_file(&save_file, save_nb, "r") == 84)
        return (84);
    name = get_player_name(save_file);
    level = get_save_level(save_file);
    if (*name)
        *default_name = name;
    if (*level)
        *default_level = level;
    fclose(save_file);
    return (0);
}