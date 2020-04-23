/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** scene middle layer
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"

dg_scene_t *scene_fight_middle(int id)
{
    dg_scene_t *scene = dg_scene_create("layer_middle_fight");
    dg_entity_t *camera = dg_ent_camera(0, 0);
    void *data[1] = {id};

    dg_entity_add_component(camera, cpt_script(&scp_fight_manager_init,
        &scp_fight_manager_loop, &scp_fight_manager_end, data));
    dg_scene_add_ent(scene, entity_player_fight_create());
    dg_scene_add_ent(scene, camera);
    dg_scene_add_sys(scene, dg_system_create(&dg_sys_animator, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_tm_render, 1));
    return scene;
}