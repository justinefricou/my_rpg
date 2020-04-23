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
    gd->object_list.object[0] = calming();
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

static void set_inventory(general_data_t *gd)
{
    gd->inventory.len = 0;
    gd->inventory.stack.x = 0;
    gd->inventory.stack.y = 20;
    for (int i = 0; i < 100; i++) {
        gd->inventory.slot[i].id = -1;
        gd->inventory.slot[i].nb = 0;
    }
    add_to_inventory(gd, 0, 10);
}

general_data_t *create_general_data(void)
{
    general_data_t *gd = malloc(sizeof(general_data_t));

    gd->options.general_volume = (sfVector2f){50, 100};
    gd->options.music = (sfVector2f){15, 100};
    gd->options.sound = (sfVector2f){30, 100};
    gd->options.resolution = 0;
    gd->player.name = "Player";
    gd->player.money = 100;
    gd->player.pv.x = 50;
    gd->player.pv.y = 100;
    gd->player.pm.x = 100;
    gd->player.pm.y = 100;
    gd->player.xp.x = 0;
    gd->player.xp.y = 20;
    set_object_list(gd);
    set_inventory(gd);
    set_default_keymap(gd);
    create_events(gd);
    set_sprite_id(gd);
    gd->maps = set_map_data();
    return gd;
}

void free_general_data(general_data_t *gd)
{
    free(gd);
}