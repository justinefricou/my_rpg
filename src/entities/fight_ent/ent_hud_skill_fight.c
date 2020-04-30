/*
** EPITECH PROJECT, 2020
** ent_hud_skill_fight
** File description:
** ent_hud_skill_fight
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "hud/hud.h"

dg_entity_t *ent_hud_skill_fight(int *previous, dg_scene_t *scene,
    dg_window_t *w)
{
    dg_entity_t *entity = dg_entity_create("hud_skill_fight");
    general_data_t *gd = w->general_data;
    void *idata[4] = {entity, scene, previous, gd};
    dg_entity_add_component(entity, cpt_script(&scp_hud_fight_init,
        &scp_hud_fight_loop, &scp_hud_fight_end, idata));
    return entity;
}

void fight_skill(int *previous, void *data, dg_window_t *w)
{
    dg_scene_t *scene = dg_scene_manager_get_scene("layer_hud_fight");

    *previous = 0;
    dg_scene_add_ent(scene, ent_hud_skill_fight(previous, scene, w));
}