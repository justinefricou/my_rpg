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

void *scp_dialogue_fight_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    dg_scene_t *scene = idata[0];
    general_data_t *gd = idata[2];
    int i = idata[3];

    data->previous = idata[1];
    data->sound_activate = dg_ressources_get_audio_by_name("hud_activate");
    data->sound_move = dg_ressources_get_audio_by_name("hud_move");
    data->side_box = ent_hud_box(875, 600, 20, 7);
    data->skill_box = ent_text(880, 600, 40, gd->skills[i].description);
    data->launch_action = 0;
    data->fx = ent_sparkle(set_sparkle());
    dg_scene_add_ent(scene, data->side_box);
    dg_scene_add_ent(scene, data->skill_box);
    dg_scene_add_ent(scene, data->fx);
    return data;
}

void scp_dialogue_fight_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;
    general_data_t *gd = w->general_data;

    if (keymap_is_clicked(w, "action", 1) ||
        keymap_is_clicked(w, "cancel", 1) ||
        keymap_is_clicked(w, "left", 1) ||
        keymap_is_clicked(w, "right", 1) ||
        keymap_is_clicked(w, "up", 1) ||
        keymap_is_clicked(w, "down", 1)) {
        sound_play(data->sound_activate);
        gd->player.turn = 1;
        data->is_active = 0;
        data->launch_action = 1;
        entity->destroy = 1;
    }
}

void scp_dialogue_fight_end(void *data)
{
    data_t *d = (data_t *)data;

    *(d->previous) = 1;
    d->side_box->destroy = 1;
    d->skill_box->destroy = 1;
    d->fx->destroy = 1;
    free(d);
}