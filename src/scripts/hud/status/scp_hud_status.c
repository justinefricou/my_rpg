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
#include "hud/hud_status.h"

void *scp_hud_status_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    dg_scene_t *scene = idata[1];
    dg_entity_t *entity = idata[0];
    dg_window_t *w = idata[3];
    dg_component_t *pos = dg_cpt_pos(350, 20);
    dg_component_t *selector = cpt_shape_rectangle((sfVector2f){350, 20},
        (sfVector2f){0, 0}, (sfColor){255, 255, 255, 100},
        (sfColor){0, 0, 0, 0});

    dg_entity_add_component(entity, pos);
    dg_entity_add_component(entity, selector);
    data->previous = idata[2];
    data->hud_box = ent_hud_box(350, 20, 32, 20);
    dg_scene_add_ent(scene, data->hud_box);
    status_set_sounds(data);
    status_set_data(data, w);
    dg_scene_manager_add_scene(data->layer);
    return data;
}

void scp_hud_status_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;

    if (keymap_is_clicked(w, "cancel", 1)) {
        sound_play(data->sound_activate);
        *(data->previous) = 1;
        data->hud_box->destroy = 1;
        entity->destroy = 1;
    }
}

void scp_hud_status_end(void *data)
{
    data_t *d = (data_t *)data;

    dg_scene_manager_remove("status");
    free(d);
}