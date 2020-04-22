/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** scene bottom layer
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

static void sys_hud(dg_scene_t *scene)
{
    dg_scene_add_sys(scene, dg_system_create(&sys_shape_rectangle, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_display_text, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_sprite, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_tm_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_script, 0));
}

dg_scene_t *scene_fight_hud(dg_window_t *w)
{
    dg_scene_t *scene = dg_scene_create("layer_hud_fight");
    general_data_t *gd = w->general_data;
    sfVector2f *size = 0;
    dg_entity_t *ent = ent_hud_progress_bar(
        (sfVector2f){1520, 20}, 8, &(gd->player.xp), sfGreen);

    size = dg_entity_get_component(ent, "scale");
    size->y = 1;
    dg_scene_add_ent(scene, dg_ent_camera(0, 0));
    dg_scene_add_ent(scene, ent_hud_progress_bar(
        (sfVector2f){20, 20}, 5, &(gd->player.pv), sfRed));
    dg_scene_add_ent(scene, ent_hud_progress_bar(
        (sfVector2f){20, 70}, 5, &(gd->player.pm), sfBlue));
    dg_scene_add_ent(scene, ent);
    sys_hud(scene);
    return scene;
}