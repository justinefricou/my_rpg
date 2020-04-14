/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** keymap
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "general_data.h"
#include "epitech_tools.h"

static const char *name[6] = {"up", "down", "left",
    "right", "action", "cancel"};

static sfKeyCode get_keymap_from_id(dg_window_t *w, int keymap)
{
    general_data_t *gd = (general_data_t *)w->general_data;

    switch (keymap)
    {
        case 0:
            return gd->options.keymap.up;
        case 1:
            return gd->options.keymap.down;
        case 2:
            return gd->options.keymap.left;
        case 3:
            return gd->options.keymap.right;
        case 4:
            return gd->options.keymap.action;
        case 5:
            return gd->options.keymap.cancel;
    }
    return 0;
}

sfKeyCode get_keymap(dg_window_t *w, char *keymap)
{
    for (int i = 0; i < 6; i++) {
        if (!dg_strcmp(keymap, name[i]))
            return get_keymap_from_id(w, i);
    }
    return 0;
}

int keymap_is_clicked(dg_window_t *w, char *keymap, int force_ignore)
{
    return key_is_clicked(w, get_keymap(w, keymap), force_ignore);
}

int keymap_is_pressed(dg_window_t *w, char *keymap)
{
    if (sfKeyboard_isKeyPressed(get_keymap(w, keymap)))
        return 1;
    return 0;
}