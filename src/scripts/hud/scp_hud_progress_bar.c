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
    sfVector2i mmemory;
    sfRectangleShape *selector;
    int activate;
    int active;
    sfMusic *sound_move;
} data_t;

void hud_progress_bar_activate(dg_entity_t *pb, int stat)
{
    script_t *script = (script_t *)dg_entity_get_component(pb, "script");
    data_t *data = script->data;

    data->activate = stat;
    data->active = stat;
}

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
    data->mmemory = (sfVector2i) {0};
    data->active = 0;
    dg_entity_add_component(entity, pos);
    selector = cpt_shape_rectangle((sfVector2f){0, 12},
        (sfVector2f){data->size * 16 * 3, 16 * 3}, color, color);
    dg_entity_add_component(entity, selector);
    data->selector = selector->data;
    return data;
}

static void hud_pb_active(dg_window_t *w, data_t *data)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(w->window);

    if ((keymap_is_clicked(w, "right", 0) ||
        (sfMouse_isButtonPressed(sfMouseLeft) && data->mmemory.x < mouse.x))
        && data->data->x < data->data->y) {
        sound_play(data->sound_move);
        data->data->x++;
    }
    if ((keymap_is_clicked(w, "left", 0) ||
        (sfMouse_isButtonPressed(sfMouseLeft) && data->mmemory.x > mouse.x))
        && data->data->x > 0) {
        sound_play(data->sound_move);
        data->data->x--;
    }
    data->mmemory = sfMouse_getPositionRenderWindow(w->window);
}

void scp_hud_progress_bar_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;
    float size = (data->data->x / data->data->y) * (data->size * 16);

    if (data->active)
        hud_pb_active(w, data);
    sfRectangleShape_setSize(data->selector, (sfVector2f){size, 8});
}

void scp_hud_progress_bar_end(void *data)
{
    data_t *d = (data_t *)data;

    free(d);
}