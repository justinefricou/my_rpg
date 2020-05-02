/*
** EPITECH PROJECT, 2020
** ent_hud_fight_inventory
** File description:
** ent_hud_fight_inventory
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "hud/hud.h"

dg_entity_t *ent_hud_fight_dialogue(int *previous, dg_scene_t *scene, int i,
    general_data_t *gd)
{
    dg_entity_t *entity = dg_entity_create("hud_fight_inventory");
    void *idata[4] = {scene, previous, gd, i};

    dg_entity_add_component(entity, cpt_script(&scp_dialogue_fight_init,
        &scp_dialogue_fight_loop, &scp_dialogue_fight_end, idata));
    dg_entity_add_component(entity, dg_cpt_pos(100, 100));
    return entity;
}