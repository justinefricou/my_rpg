/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** hud : menu selector
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "hud.h"

dg_entity_t *ent_hud_clues(int *previous, dg_scene_t *scene)
{
    dg_entity_t *entity = dg_entity_create("hud_inventory");
    void *idata[3] = {entity, scene, previous};

    dg_entity_add_component(entity, cpt_script(&scp_hud_clues_init,
        &scp_hud_clues_loop, &scp_hud_clues_end, idata));
    return entity;
}