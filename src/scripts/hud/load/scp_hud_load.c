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
#include "hud/hud_load.h"
#include "save_load.h"

static void data_init_hud(data_t *data, void **idata,
    dg_component_t *selector)
{
    data->previous = idata[2];
    data->selector = selector->data;
    data->select = 0;
    data->load_on_exit = 0;
}

void *scp_hud_load_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    dg_scene_t *scene = idata[1];
    dg_entity_t *entity = idata[0];
    dg_component_t *pos = dg_cpt_pos(350, 20);
    dg_component_t *selector = cpt_shape_rectangle((sfVector2f){-5, 165},
        (sfVector2f){30 * 16 * 3 + 10, 5 * 16 * 3 + 10}, (sfColor){0, 0, 0, 0},
        (sfColor){255, 255, 255, 255});

    dg_entity_add_component(entity, pos);
    dg_entity_add_component(entity, selector);
    data_init_hud(data, idata, selector);
    sfRectangleShape_setOutlineThickness(data->selector, 5);
    data->layer = scene_tmp_hover("load");
    load_set_data(data, scene);
    dg_scene_manager_add_scene(data->layer);
    load_set_sounds(data);
    return data;
}

void load_active(dg_window_t *w, data_t *data)
{
    general_data_t *general_data = w->general_data;

    if (keymap_is_clicked(w, "down", 1) && data->select < 2) {
        sound_play(data->sound_move);
        data->select++;
    }
    if (keymap_is_clicked(w, "up", 1) && data->select > 0) {
        sound_play(data->sound_move);
        data->select--;
    }
    hud_load_manage_mouse(w, data);
    if (keymap_is_clicked(w, "action", 1)) {
        sound_play(data->sound_activate);
        if (load_saved_game(general_data, data->select) == 0)
            data->load_on_exit = 1;
    }
}

void scp_hud_load_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;

    data->w = w;
    load_active(w, data);
    load_update_position(data);
    if (keymap_is_clicked(w, "cancel", 1) || data->load_on_exit) {
        sound_play(data->sound_activate);
        *(data->previous) = 1;
        entity->destroy = 1;
    }
}

void scp_hud_load_end(void *data)
{
    data_t *d = (data_t *)data;

    for (int i = 0; i < 4; i++)
            d->hud_box[i]->destroy = 1;
    dg_scene_manager_remove("load");
    if (d->load_on_exit) {
        create_game_scenes(d->w->general_data, "island");
        sfMusic_stop(dg_ressources_get_audio_by_name("menu_theme"));
        sfMusic_play(dg_ressources_get_audio_by_name("game_theme"));
        dg_scene_manager_remove("main_menu");
        dg_scene_manager_remove("main_menu_hover");
    }
    free(d);
}