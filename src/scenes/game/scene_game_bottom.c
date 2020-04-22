/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** scene bottom layer
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"

dg_scene_t *scene_game_bottom(int **map, dg_scene_t *event)
{
    dg_scene_t *scene = dg_scene_create("layer_bottom");
    dg_entity_t *camera = dg_ent_camera(0, 0);
    dg_entity_t *follow = dg_get_entity(event->entities, "camera");
    sfVector2f *fol_pos = dg_entity_get_component(follow, "pos");
    sfVector2f *cam_pos = dg_entity_get_component(camera, "pos");
    void *data[2] = {fol_pos, cam_pos};

    dg_entity_add_component(camera, cpt_script(&scp_link_camera_init,
        &scp_link_camera_loop, &scp_player_controller_end, data));
    dg_scene_add_ent(scene, camera);
    dg_scene_add_ent(scene, ent_map("map", 3, map, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_tm_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_script, 0));
    return scene;
}