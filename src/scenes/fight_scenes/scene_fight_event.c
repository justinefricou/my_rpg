/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** scene_endless_waves
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "general_data.h"

static void scene_add_ent(dg_scene_t *scene, int **map)
{
    dg_entity_t *camera = dg_ent_camera(0, 0);

    dg_scene_add_ent(scene, camera);
}

static void scene_add_sys(dg_scene_t *scene)
{
    dg_scene_add_sys(scene, dg_system_create(&sys_camera, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_display_text, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_shape_rectangle, 1));
    dg_scene_add_sys(scene, dg_system_create(&dg_sys_animator, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_tm_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_script, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_interact_dialogue, 1));
}

dg_scene_t *scene_fight_event(int **map)
{
    dg_scene_t *scene = dg_scene_create("layer_event_fight");

    scene_add_ent(scene, map);
    scene_add_sys(scene);
    return scene;
}