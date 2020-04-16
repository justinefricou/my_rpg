/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** general data
*/

#include <stdlib.h>
#include "general_data.h"
#include "object.h"

static void set_object_list(general_data_t *gd)
{
    gd->object_list.len = OBJECT_LIST;
    gd->object_list.object[0] = object_create("Potion", 0, NULL);
}

static void set_default_keymap(general_data_t *gd)
{
    gd->options.keymap.action = sfKeySpace;
    gd->options.keymap.cancel = sfKeyEscape;
    gd->options.keymap.up = sfKeyUp;
    gd->options.keymap.down = sfKeyDown;
    gd->options.keymap.left = sfKeyLeft;
    gd->options.keymap.right = sfKeyRight;
    gd->block_input = 0;
}

general_data_t *create_general_data(void)
{
    general_data_t *gd = malloc(sizeof(general_data_t));

    gd->options.general_volume = (sfVector2f){100, 100};
    gd->options.music = (sfVector2f){100, 100};
    gd->options.sound = (sfVector2f){100, 100};
    gd->options.resolution = 0;
    gd->inventory.len = 0;
    gd->inventory.slot = NULL;
    gd->player.name = "";
    gd->player.pv = 100;
    gd->player.pm = 100;
    set_object_list(gd);
    set_default_keymap(gd);
    return gd;
}

void free_general_data(general_data_t *gd)
{
    free(gd);
}