/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Saves options : sound and music volume, resolution and keys.
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/System/Vector2.h>
#include "libmy.h"
#include "save_load.h"

static void save_key(char *label, sfKeyCode key, FILE *save_file)
{
    write_str_in_save_file(label, save_file);
    write_int_in_save_file(key, save_file);
    fwrite("\n", sizeof(char), 1, save_file);
}

void save_keymap(keymap_t keymap, FILE *save_file)
{
    char *labels[6] = {"keymap_up ", "keymap_left ", "keymap_down ",
                       "keymap_right ", "keymap_action ", "keymap_cancel "};
    sfKeyCode keys[6] = {keymap.up, keymap.left, keymap.down, keymap.right,
                         keymap.action, keymap.cancel};

    for (int i = 0; i < 6; i++)
        save_key(labels[i], keys[i], save_file);
}