/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** scene bottom layer
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "general_data.h"

dg_scene_t *scene_game_hud(general_data_t *gd)
{
    dg_scene_t *scene = dg_scene_create("layer_hud");
    sfVector2f *size = 0;
    dg_entity_t *ent = ent_hud_progress_bar(
        (sfVector2f){1520, 20}, 8, &(gd->player.xp), sfGreen);

    dg_scene_add_ent(scene, dg_ent_camera(0, 0));
    dg_scene_add_ent(scene, ent_hud_progress_bar(
        (sfVector2f){20, 20}, 5, &(gd->player.pv), sfRed));
    dg_scene_add_ent(scene, ent_hud_progress_bar(
        (sfVector2f){20, 70}, 5, &(gd->player.pm), sfBlue));
    dg_scene_add_ent(scene, ent);
    dg_scene_add_sys(scene, dg_system_create(&sys_shape_rectangle, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_display_text, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_sprite, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_tm_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_script, 0));
    return scene;
}