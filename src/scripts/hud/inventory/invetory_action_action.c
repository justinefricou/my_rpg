/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** script player controller
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "hud/hud_inventory.h"
#include "general_data.h"

void inv_use(int *previous, void *data, dg_window_t *w)
{
    data_t *d = data;
    general_data_t *gd = w->general_data;
    int id = 0;

    id = gd->inventory.slot[d->selector.select % 24].id;
    if (gd->object_list.object[id].consomable)
        remove_from_inventory(gd, d->selector.select, 1);
    sound_play(d->sound_activate);
    if (gd->object_list.object[gd->inventory.slot[
            d->selector.select].id].action)
        gd->object_list.object[gd->inventory.slot[
            d->selector.select].id].action(w);
    d->launch_action = 2;
}

void inv_throw(int *previous, void *data, dg_window_t *w)
{
    data_t *d = data;
    general_data_t *gd = w->general_data;
    int id = 0;

    remove_from_inventory(gd, d->selector.select, 1);
    sound_play(d->sound_activate);
    d->launch_action = 2;
}

void inv_cancel(int *previous, void *data, dg_window_t *w)
{
    data_t *d = data;

    d->launch_action = 2;
}