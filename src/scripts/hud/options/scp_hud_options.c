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
#include "general_data.h"
#include "hud/hud_options.h"
#include "epitech_tools.h"
#include "save_load.h"

void *scp_hud_options_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    dg_scene_t *scene = idata[1];
    dg_window_t *w = idata[3];
    dg_entity_t *entity = idata[0];

    data->hover_layer = scene_tmp_hover("options_hover");
    dg_scene_manager_add_scene(data->hover_layer);
    data->previous = idata[2];
    options_set_data(data, scene, entity, w->general_data);
    return data;
}

static void hud_options_active(dg_window_t *w, data_t *data)
{
    if (keymap_is_clicked(w, "down", 1) && data->select < 9) {
        sound_play(data->sound_move);
        data->select++;
    }
    if (keymap_is_clicked(w, "up", 1) && data->select > 0) {
        sound_play(data->sound_move);
        data->select--;
    }
    hud_menu_manage_mouse(w, data);
    reset_selected(data);
    act_by_selected(data);
}

void scp_hud_options_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;
    general_data_t *gd = w->general_data;

    if (data->is_active)
        hud_options_active(w, data);
    if (keymap_is_clicked(w, "cancel", 1)) {
        sound_play(data->sound_activate);
        *(data->previous) = 1;
        entity->destroy = 1;
        save_options(gd->options);
    }
    data->selector.pos->y = 200 + data->select * 80;
    update_sound(data, gd);
}

void scp_hud_options_end(void *data)
{
    data_t *d = (data_t *)data;

    dg_scene_manager_remove("options_hover");
    d->content.main.data->destroy = 1;
    d->content.volume_general.data->destroy = 1;
    free(d);
}