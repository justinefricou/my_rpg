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

static void options_set_main(data_t *data)
{
    data->hud_box = ent_hud_box(490, 20, 29, 20);
}

static void options_set_escape(data_t *data)
{
    data->hud_box = ent_hud_box(350, 20, 32, 20);
}

void options_set_data(data_t *data, dg_scene_t *scene,
    dg_entity_t *entity, general_data_t *gd)
{
    dg_component_t *selector = cpt_shape_rectangle((sfVector2f){350, 20},
        (sfVector2f){0, 0}, (sfColor){255, 255, 255, 100},
        (sfColor){0, 0, 0, 0});
    if (!dg_strcmp(scene->name, "escape_menu"))
        options_set_escape(data);
    else
        options_set_main(data);
    data->gvm = gd->options.general_volume.x;
    data->general_volume = ent_hud_progress_bar(
        (sfVector2f){800, 200}, 10, &(gd->options.general_volume), sfWhite);
    dg_scene_add_ent(scene, data->hud_box);
    dg_scene_add_ent(data->hover_layer, data->general_volume);
    data->selector = selector->data;
    dg_entity_add_component(entity, selector);
    options_set_sounds(data);
}