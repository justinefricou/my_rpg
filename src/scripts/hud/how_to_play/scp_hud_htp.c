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
#include "hud/hud_htp.h"

void *scp_hud_htp_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    dg_scene_t *scene = idata[1];
    dg_entity_t *entity = idata[0];

    dg_entity_add_component(entity, dg_cpt_pos(350, 20));
    data->previous = idata[2];
    data->layer = scene_tmp_hover("htp");
    data->hud_box = ent_hud_box(490, 20, 29, 20);
    dg_scene_add_ent(scene, data->hud_box);
    dg_scene_manager_add_scene(data->layer);
    htp_set_text(data);
    htp_set_sounds(data);
    return data;
}

void scp_hud_htp_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;

    if (keymap_is_clicked(w, "cancel", 1)) {
        sound_play(data->sound_activate);
        *(data->previous) = 1;
        entity->destroy = 1;
    }
}

void scp_hud_htp_end(void *data)
{
    data_t *d = (data_t *)data;

    d->hud_box->destroy = 1;
    dg_scene_manager_remove("htp");
    free(d);
}