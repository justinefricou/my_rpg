/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** hud : options
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "hud/hud.h"

dg_entity_t *ent_hud_options(int *previous, dg_scene_t *scene, dg_window_t *w)
{
    dg_entity_t *entity = dg_entity_create("hud_options");
    void *idata[4] = {entity, scene, previous, w};

    dg_entity_add_component(entity, dg_cpt_pos(350, 20));
    dg_entity_add_component(entity, cpt_script(&scp_hud_options_init,
        &scp_hud_options_loop, &scp_hud_options_end, idata));
    return entity;
}