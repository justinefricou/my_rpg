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
#include "hud/hud_options.h"
#include "epitech_tools.h"
#include "general_data.h"

static void options_set_sounds(data_t *data)
{
    data->sound_activate = dg_ressources_get_audio_by_name("hud_activate");
    data->sound_move = dg_ressources_get_audio_by_name("hud_move");
}

static void opt_add_ent_data(data_t *data)
{
    dg_scene_add_ent(data->hover_layer, data->content.volume_general.data);
    dg_scene_add_ent(data->hover_layer, data->content.volume_music.data);
    dg_scene_add_ent(data->hover_layer, data->content.volume_sound.data);
    dg_scene_add_ent(data->hover_layer, data->content.keymap_action.data);
    dg_scene_add_ent(data->hover_layer, data->content.keymap_cancel.data);
    dg_scene_add_ent(data->hover_layer, data->content.keymap_down.data);
    dg_scene_add_ent(data->hover_layer, data->content.keymap_left.data);
    dg_scene_add_ent(data->hover_layer, data->content.keymap_right.data);
    dg_scene_add_ent(data->hover_layer, data->content.keymap_up.data);
}

static void opt_add_ent_name(data_t *data)
{
    dg_scene_add_ent(data->hover_layer, data->content.main.name);
    dg_scene_add_ent(data->hover_layer, data->content.volume_general.name);
    dg_scene_add_ent(data->hover_layer, data->content.volume_music.name);
    dg_scene_add_ent(data->hover_layer, data->content.volume_sound.name);
    dg_scene_add_ent(data->hover_layer, data->content.keymap_action.name);
    dg_scene_add_ent(data->hover_layer, data->content.keymap_cancel.name);
    dg_scene_add_ent(data->hover_layer, data->content.keymap_down.name);
    dg_scene_add_ent(data->hover_layer, data->content.keymap_left.name);
    dg_scene_add_ent(data->hover_layer, data->content.keymap_right.name);
    dg_scene_add_ent(data->hover_layer, data->content.keymap_up.name);
}

void options_set_data(data_t *data, dg_scene_t *scene,
    dg_entity_t *entity, general_data_t *gd)
{
    dg_component_t *selector = cpt_shape_rectangle((sfVector2f){350, 20},
        (sfVector2f){0, 0}, (sfColor){255, 255, 255, 100},
        (sfColor){0, 0, 0, 0});
    if (!dg_strcmp(scene->name, "escape_menu"))
        options_set_escape(data, gd);
    else
        options_set_main(data, gd);
    data->select = 0;
    data->is_active = 1;
    data->mouse_memory = (sfVector2i) {0};
    data->gvm = gd->options.general_volume.x;
    dg_scene_add_ent(scene, data->content.main.data);
    opt_add_ent_data(data);
    opt_add_ent_name(data);
    dg_scene_add_ent(data->hover_layer, data->selector.entity);
    data->selector.pos = dg_entity_get_component(data->selector.entity, "pos");
    dg_entity_add_component(entity, selector);
    options_set_sounds(data);
}