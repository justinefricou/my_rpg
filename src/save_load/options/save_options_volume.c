/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Saves volumes options : sound, music and general.
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/System/Vector2.h>
#include "libmy.h"
#include "save_load.h"

void save_general_volume(options_t options, FILE *save_file)
{
    write_str_in_save_file("general_volume ", save_file);
    write_int_in_save_file(options.general_volume.x, save_file);
    fwrite("\n", sizeof(char), 1, save_file);
    write_str_in_save_file("general_volume_max ", save_file);
    write_int_in_save_file(options.general_volume.y, save_file);
    fwrite("\n", sizeof(char), 1, save_file);
}

void save_music_volume(options_t options, FILE *save_file)
{
    write_str_in_save_file("music_volume ", save_file);
    write_int_in_save_file(options.music.x, save_file);
    fwrite("\n", sizeof(char), 1, save_file);
    write_str_in_save_file("music_volume_max ", save_file);
    write_int_in_save_file(options.music.y, save_file);
    fwrite("\n", sizeof(char), 1, save_file);
}

void save_sound_volume(options_t options, FILE *save_file)
{
    write_str_in_save_file("sound_volume ", save_file);
    write_int_in_save_file(options.sound.x, save_file);
    fwrite("\n", sizeof(char), 1, save_file);
    write_str_in_save_file("sound_volume_max ", save_file);
    write_int_in_save_file(options.sound.y, save_file);
    fwrite("\n", sizeof(char), 1, save_file);
}