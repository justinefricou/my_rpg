/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** scene bottom layer
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

dg_scene_t *scene_fight_bottom(int **map, dg_scene_t *event)
{
    dg_scene_t *scene = dg_scene_create("layer_bottom_fight");
    dg_entity_t *camera = dg_ent_camera(0, 0);

    dg_scene_add_ent(scene, dg_ent_camera(0, 0));
    dg_scene_add_ent(scene, camera);
    dg_scene_add_ent(scene, ent_map("background_fight_1", 4, map, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_tm_render, 1));
    return scene;
}