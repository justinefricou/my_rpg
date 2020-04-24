/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Saves options : sound and music volume, resolution and keys.
*/

#include <stdio.h>
#include "libmy.h"
#include "save_load.h"

static void save_resolution(int resolution, FILE *save_file)
{
    write_str_in_save_file("resolution ", save_file);
    write_int_in_save_file(resolution, save_file);
    fwrite("\n", sizeof(char), 1, save_file);
}

static int write_options_in_save_file(options_t options, FILE *save_file)
{
    save_general_volume(options, save_file);
    save_music_volume(options, save_file);
    save_sound_volume(options, save_file);
    save_resolution(options.resolution, save_file);
    save_keymap(options.keymap, save_file);
    return (0);
}

int save_options(options_t options)
{
    FILE *save_file = NULL;
    int return_value = 0;

    return_value = open_save_file(&save_file, -1, "w");
    if (return_value != 84) {
        return_value = write_options_in_save_file(options, save_file);
        fclose(save_file);
    }
    return (return_value);
}