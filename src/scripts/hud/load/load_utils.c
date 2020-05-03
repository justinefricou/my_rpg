/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** load
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "hud/hud_load.h"

void load_update_position(data_t *data)
{
    int select = data->select;
    sfVector2f pos = {95, 165 + select * 270};

    sfRectangleShape_setPosition(data->selector, pos);
}

void hud_load_manage_mouse(dg_window_t *w, data_t *data)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(w->window);
    sfVector2f pos = {mouse_pos.x - 350, mouse_pos.y - 200};

    if (3 * 250 < pos.y || pos.y < 0
        || pos.x < 0 || pos.x > 1880 ||
        (mouse_pos.x == data->mouse_memory.x
        && mouse_pos.y == data->mouse_memory.y))
        return;
    data->mouse_memory.x = mouse_pos.x;
    data->mouse_memory.y = mouse_pos.y;
    for (int i = 0; i < 3; i++)
        if (pos.y < (250 * (i + 1))) {
            (i != data->select) ? sound_play(data->sound_move) : 0;
            data->select = i;
            return;
        }
}