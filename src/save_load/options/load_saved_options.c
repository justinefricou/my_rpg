/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Loads saved options : sound and music volume, resolution and keys.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libmy.h"
#include "save_load.h"

static int load_saved_resolution(options_t *options, FILE *save_file)
{
    char *line = NULL;
    int start = 0;

    line = get_line_from_save_file(save_file);
    if (!line) {
        write(2, "Error : resolution could not be loaded.\n", 40);
        return (84);
    }
    start = my_strlen("resolution ");
    options->resolution = get_nbr_until(&(line[start]), 0);
    free(line);
}

static int read_options_in_save_file(options_t *options, FILE *save_file)
{
    if (load_saved_general_volume(options, save_file) == 84)
        return (84);
    if (load_saved_music_volume(options, save_file) == 84)
        return (84);
    if (load_saved_sound_volume(options, save_file) == 84)
        return (84);
    if (load_saved_resolution(options, save_file) == 84)
        return (84);
    if (load_saved_keymap(&(options->keymap), save_file) == 84)
        return (84);
    return (0);
}

int load_saved_options(options_t *options)
{
    FILE *save_file = NULL;
    int return_value = 0;

    return_value = open_save_file(&save_file, -1, "r");
    if (return_value != 84) {
        return_value = read_options_in_save_file(options, save_file);
        fclose(save_file);
    }
    return (return_value);
}