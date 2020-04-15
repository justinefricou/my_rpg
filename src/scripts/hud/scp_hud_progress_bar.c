/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** hud progress bar
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"

typedef struct data {
    sfVector2f *pos;
    int size;
    sfVector2f *data;
    sfRectangleShape *selector;
    int active;
    sfMusic *sound_move;
} data_t;

void *scp_hud_progress_bar_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    dg_entity_t *entity = idata[0];
    sfVector2f *dpos = idata[1];
    dg_component_t *pos = dg_cpt_pos(dpos->x, dpos->y);
    sfColor color = *((sfColor *)idata[4]);
    dg_component_t *selector = 0;

    data->sound_move = dg_ressources_get_audio_by_name("hud_move");
    data->pos = pos->data;
    data->data = (sfVector2f *)idata[3];
    data->size = *((int *)idata[2]);
    data->active = 1;
    dg_entity_add_component(entity, pos);
    selector = cpt_shape_rectangle((sfVector2f){0, 0},
        (sfVector2f){data->size * 16 * 3, 16 * 3}, color, color);
    dg_entity_add_component(entity, selector);
    data->selector = selector->data;
    return data;
}

static void hud_pb_active(dg_window_t *w, data_t *data)
{
    if (keymap_is_clicked(w, "right", 0) && data->data->x < data->data->y) {
        sound_play(data->sound_move);
        data->data->x++;
    }
    if (keymap_is_clicked(w, "left", 0) && data->data->x > 0) {
        sound_play(data->sound_move);
        data->data->x--;
    }
}

void scp_hud_progress_bar_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;
    float size = (data->data->x / data->data->y) * (data->size * 16 * 3);

    if (data->active)
        hud_pb_active(w, data);
    sfRectangleShape_setSize(data->selector, (sfVector2f){size, 16/* * 3*/});
}

void scp_hud_progress_bar_end(void *data)
{
    data_t *d = (data_t *)data;

    free(d);
}