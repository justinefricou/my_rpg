/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** scene main menu hover
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "hud.h"

dg_scene_t *scene_main_menu_hover(void)
{
    dg_scene_t *scene = dg_scene_create("main_menu_hover");

    dg_scene_add_ent(scene, dg_ent_camera(0, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_display_text, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_shape_rectangle, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_tm_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_button, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_script, 0));
    return scene;
}