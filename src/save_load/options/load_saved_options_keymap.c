/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Saves options : sound and music volume, resolution and keys.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/System/Vector2.h>
#include "libmy.h"
#include "save_load.h"

static int load_saved_key(char *label, sfKeyCode *key, FILE *save_file)
{
    char *line = NULL;
    int start = 0;

    line = get_line_from_save_file(save_file);
    if (!line) {
        write(2, "Error : key (", 13);
        write(2, label, my_strlen(label) - 1);
        write(2, ") could not be loaded.\n", 23);
        return (84);
    }
    start = my_strlen(label);
    *key = get_nbr_until(&(line[start]), 0);
    free(line);
}

int load_saved_keymap(keymap_t *keymap, FILE *save_file)
{
    char *labels[6] = {"keymap_up ", "keymap_left ", "keymap_down ",
                    "keymap_right ", "keymap_action ", "keymap_cancel "};
    sfKeyCode *keys[6] = {&(keymap->up), &(keymap->left), &(keymap->down),
                        &(keymap->right), &(keymap->action),
                        &(keymap->cancel)};

    for (int i = 0; i < 6; i++) {
        if (load_saved_key(labels[i], keys[i], save_file) == 84)
            return (84);
    }
}