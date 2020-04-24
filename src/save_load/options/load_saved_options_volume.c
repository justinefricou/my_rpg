/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Loads saved volumes options : sound, music and general.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/System/Vector2.h>
#include "libmy.h"
#include "save_load.h"

int load_saved_general_volume(options_t *options, FILE *save_file)
{
    char *line = NULL;
    int start = 0;

    line = get_line_from_save_file(save_file);
    if (!line) {
        write(2, "Error : general volume could not be loaded.\n", 44);
        return (84);
    }
    start = my_strlen("general_volume ");
    options->general_volume.x = get_nbr_until(&(line[start]), 0);
    free(line);
    line = get_line_from_save_file(save_file);
    if (!line) {
        write(2, "Error : max general volume could not be loaded.\n", 48);
        return (84);
    }
    start = my_strlen("general_volume_max ");
    options->general_volume.y = get_nbr_until(&(line[start]), 0);
    free(line);
    return (0);
}

int load_saved_music_volume(options_t *options, FILE *save_file)
{
    char *line = NULL;
    int start = 0;

    line = get_line_from_save_file(save_file);
    if (!line) {
        write(2, "Error : music volume could not be loaded.\n", 42);
        return (84);
    }
    start = my_strlen("music_volume ");
    options->music.x = get_nbr_until(&(line[start]), 0);
    free(line);
    line = get_line_from_save_file(save_file);
    if (!line) {
        write(2, "Error : max music volume could not be loaded.\n", 46);
        return (84);
    }
    start = my_strlen("music_volume_max ");
    options->music.y = get_nbr_until(&(line[start]), 0);
    free(line);
    return (0);
}

int load_saved_sound_volume(options_t *options, FILE *save_file)
{
    char *line = NULL;
    int start = 0;

    line = get_line_from_save_file(save_file);
    if (!line) {
        write(2, "Error : sound volume could not be loaded.\n", 42);
        return (84);
    }
    start = my_strlen("sound_volume ");
    options->sound.x = get_nbr_until(&(line[start]), 0);
    free(line);
    line = get_line_from_save_file(save_file);
    if (!line) {
        write(2, "Error : max sound volume could not be loaded.\n", 46);
        return (84);
    }
    start = my_strlen("sound_volume_max ");
    options->sound.y = get_nbr_until(&(line[start]), 0);
    free(line);
    return (0);
}