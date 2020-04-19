/*
** EPITECH PROJECT, 2020
** script_monster
** File description:
** script player controller
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "hud/hud_inventory.h"
#include "general_data.h"

static void inv_set_stack_text(data_t *data, int slot,
    int index, general_data_t *gd)
{
    char text[6] = {0};
    int nb = gd->inventory.slot[index].nb;
    int len = 0;

    if (nb < 1) {
        sfText_setString(data->slots.slots[slot].quantity.text, "");
        return;
    }
    for (int i = nb; i > 0; i /= 10, len++);
    text[0] = 'x';
    for (int i = len; i > 0; i--) {
        text[i] = '0' + (nb % 10);
        nb /= 10;
    }
    sfText_setString(data->slots.slots[slot].quantity.text, text);
}

void inventory_update_slot(data_t *data, general_data_t *gd)
{
    int slot = data->selector.defilement * 4;

    for (int i = 0; i < NB_SLOT; i++) {
        if (slot < gd->inventory.len) {
            inventory_active_slot(data, i, 1);
            data->slots.slots[i].icon.id->id =
                gd->object_list.object[gd->inventory.slot[slot].id].icon_id;
            sfText_setString(data->slots.slots[i].name.text,
                gd->object_list.object[gd->inventory.slot[slot].id].name);
            inv_set_stack_text(data, i, slot, gd);
        } else {
            inventory_active_slot(data, i, 0);
        }
        slot++;
    }
}