/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** scene main menu hover
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "hud/hud.h"

dg_scene_t *scene_tmp_hover_ws(char *name)
{
    dg_scene_t *scene = dg_scene_create(name);

    dg_scene_add_ent(scene, dg_ent_camera(0, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_shape_rectangle, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_display_text, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_sprite, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_tm_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_button, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_script, 0));
    return scene;
}