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
#include "hud_menu_selector.h"

sfVector2f get_longest_name(data_t *data)
{
    int len = data->llen;
    sfVector2f blen = {0};
    sfVector2f alen = {0};
    dg_entity_t *entity = 0;
    sfText *text = 0;

    for (int i = 0; i < len; i++) {
        entity = data->buttons[i];
        text = (sfText *)dg_entity_get_component(entity, "text");
        alen =  (sfVector2f){sfText_getGlobalBounds(text).width,
            sfText_getGlobalBounds(text).height};
        if (blen.x < alen.x)
            blen = alen;
    }
    return blen;
}

dg_entity_t **create_buttons(sfVector2f pos, dg_scene_t *scene,
    button_t *button_list, int len)
{
    dg_entity_t **buttons = malloc(sizeof(dg_entity_t *) * len);

    for (int i = 0; button_list[i].name; i++) {
        buttons[i] = ent_text(pos.x + 10, pos.y + i * (3 * 16) - 5,
            40, button_list[i].name);
        dg_scene_add_ent(scene, buttons[i]);
    }
    return buttons;
}

void update_position(data_t *data)
{
    sfVector2f difference = {data->pos->x - data->pos_memory.x,
        data->pos->y - data->pos_memory.y};
    sfVector2f *pos = 0;

    if (difference.x || difference.y) {
        for (int i = 0; i < data->llen; i++) {
            pos = (sfVector2f *)dg_entity_get_component(data->buttons[i],
                "pos");
            pos->x += difference.x;
            pos->y += difference.y;
        }
        if (data->hud_box) {
            pos = (sfVector2f *)dg_entity_get_component(data->hud_box,
                    "pos");
            pos->x += difference.x;
            pos->y += difference.y;
        }
    }
    data->pos_memory = (sfVector2f){data->pos->x, data->pos->y};
}