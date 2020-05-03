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
    dg_scene_add_ent(scene, entity_enemy_fight_create(id));
    dg_scene_add_ent(scene, camera);
    dg_scene_add_sys(scene, dg_system_create(&dg_sys_animator, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_tm_render, 1));
    return scene;
}

dg_animator_t *set_enemy_animator_fisherman(void)
{
    dg_spritesheet_t *ss = dg_ressources_get_spritesheet_by_name("enemy_4");
    dg_animator_t *animator = dg_animator_create();
    dg_animation_t *anim = 0;

    anim = dg_animation_create(ss, 3);
    dg_animation_add(anim, 0);
    dg_animation_add(anim, 1);
    dg_animation_add(anim, 2);
    dg_animator_add(animator, "idle", anim);
    return animator;
}