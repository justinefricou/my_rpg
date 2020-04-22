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
#include "hud/hud_clues.h"

void *scp_hud_clues_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    dg_scene_t *scene = idata[1];
    dg_entity_t *entity = idata[0];

    dg_entity_add_component(entity, dg_cpt_pos(350, 20));
    data->previous = idata[2];
    data->hud_box = ent_hud_box(350, 20, 32, 20);
    data->layer = scene_tmp_hover("clues");
    dg_scene_add_ent(scene, data->hud_box);
    clues_set_sounds(data);
    clues_set_data(data);
    dg_scene_manager_add_scene(data->layer);
    return data;
}

void clues_active(dg_window_t *w, data_t *data)
{
    general_data_t *gd = w->general_data;

    if (w->events.keyboard_pressed_down && data->select <gd->clues.len - 1) {
        sound_play(data->sound_move);
        data->select++;
    }
    if (w->events.keyboard_pressed_up && data->select > 0) {
        sound_play(data->sound_move);
        data->select--;
    }
    clues_update(data, w);
}

void scp_hud_clues_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;
    general_data_t *gd = w->general_data;

    if (gd->clues.len > 0)
        clues_active(w, data);
    if (keymap_is_clicked(w, "cancel", 1)) {
        sound_play(data->sound_activate);
        *(data->previous) = 1;
        entity->destroy = 1;
    }
}

void scp_hud_clues_end(void *data)
{
    data_t *d = (data_t *)data;

    dg_scene_manager_remove("clues");
    d->hud_box->destroy = 1;
    free(d);
}