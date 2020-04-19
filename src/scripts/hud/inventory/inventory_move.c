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

static void hud_inv_right(dg_window_t *w, data_t *data)
{
    general_data_t *gd = w->general_data;

    if (data->selector.select % 4 < 3
        && data->selector.select + 1 < gd->inventory.len) {
        sound_play(data->sound_move);
        data->selector.select++;
    }
}

static void hud_inv_left(dg_window_t *w, data_t *data)
{
    if (data->selector.select % 4 > 0) {
        sound_play(data->sound_move);
        data->selector.select--;
    }
}

static void hud_inv_up(dg_window_t *w, data_t *data)
{
    if (data->selector.select >= 4) {
        sound_play(data->sound_move);
        data->selector.select -= 4;
    }
}

static void hud_inv_down(dg_window_t *w, data_t *data)
{
    general_data_t *gd = w->general_data;

    if (data->selector.select + 4 < gd->inventory.len) {
        sound_play(data->sound_move);
        data->selector.select += 4;
    }
}

void inventory_manage_move(dg_window_t *w, data_t *data)
{
    (keymap_is_clicked(w, "left", 0)) ? hud_inv_left(w, data) : 0;
    (keymap_is_clicked(w, "right", 0)) ? hud_inv_right(w, data) : 0;
    (keymap_is_clicked(w, "up", 0)) ? hud_inv_up(w, data) : 0;
    (keymap_is_clicked(w, "down", 0)) ? hud_inv_down(w, data) : 0;
}