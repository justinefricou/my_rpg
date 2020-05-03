/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** ent_intro
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"

dg_entity_t *ent_intro(void)
{
    dg_entity_t *entity = dg_entity_create("intro");

    dg_entity_add_component(entity, cpt_script(&scp_intro_init,
        &scp_intro_loop, &scp_intro_end, NULL));
    return entity;
}
