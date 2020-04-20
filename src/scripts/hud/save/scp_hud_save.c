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
#include "hud/hud_save.h"

void *scp_hud_save_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    dg_scene_t *scene = idata[1];
    dg_entity_t *entity = idata[0];
    dg_component_t *pos = dg_cpt_pos(350, 20);
    dg_component_t *selector = cpt_shape_rectangle((sfVector2f){-5, 165},
        (sfVector2f){32 * 16 * 3 + 10, 5 * 16 * 3 + 10}, (sfColor){0, 0, 0, 0},
        (sfColor){255, 255, 255, 255});

    dg_entity_add_component(entity, pos);
    dg_entity_add_component(entity, selector);
    data->previous = idata[2];
    data->selector = selector->data;
    data->select = 0;
    sfRectangleShape_setOutlineThickness(data->selector, 5);
    data->layer = scene_tmp_hover("save");
    save_set_data(data, scene);
    dg_scene_manager_add_scene(data->layer);
    save_set_sounds(data);
    return data;
}

void save_active(dg_window_t *w, data_t *data)
{
    if (keymap_is_clicked(w, "down", 1) && data->select < 2) {
        sound_play(data->sound_move);
        data->select++;
    }
    if (keymap_is_clicked(w, "up", 1) && data->select > 0) {
        sound_play(data->sound_move);
        data->select--;
    }
}

void scp_hud_save_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;

    save_active(w, data);
    save_update_position(data);
    if (keymap_is_clicked(w, "cancel", 1)) {
        sound_play(data->sound_activate);
        *(data->previous) = 1;
        entity->destroy = 1;
    }
}

void scp_hud_save_end(void *data)
{
    data_t *d = (data_t *)data;

    for (int i = 0; i < 4; i++)
            d->hud_box[i]->destroy = 1;
    dg_scene_manager_remove("save");
    free(d);
}