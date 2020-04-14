/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** how to play
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "hud_load.h"

void load_set_sounds(data_t *data)
{
    data->sound_activate = dg_ressources_get_audio_by_name("hud_activate");
    data->sound_move = dg_ressources_get_audio_by_name("hud_move");
}

/*data_t *menu_selector_set_data(dg_component_t *pos,
    button_t *button_list, dg_scene_t *scene, int has_box)
{
    data_t *data = malloc(sizeof(data_t));

    data->select = 0;
    data->is_active = 1;
    data->llen = 0;
    data->pos = pos->data;
    data->pos_memory = *(data->pos);
    if (!button_list)
        return data;
    for (data->llen = 0; button_list[data->llen].name; data->llen++);
    data->buttons = create_buttons(*(data->pos), scene, button_list,
        data->llen);
    if (has_box)
        data->hud_box = ent_hud_box(data->pos->x, data->pos->y,
        (int)((get_longest_name(data).x + 10)/ (16 * 3) + 0.9), data->llen);
    else
        data->hud_box = NULL;
    data->button_list = button_list;
    hud_selector_set_sounds(data);
    return data;
}*/