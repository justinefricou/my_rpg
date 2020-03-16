/*
** EPITECH PROJECT, 2020
** ent_map
** File description:
** ent_map
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

dg_entity_t *ent_map(int id, float scale, float x, float y)
{
    dg_entity_t *background_menu = dg_entity_create("map");

    dg_entity_add_component(background_menu, dg_cpt_pos(x, y));
    dg_entity_add_component(background_menu, cpt_scale(scale, scale));
    dg_entity_add_component(background_menu, cpt_spritesheet(id));
    return background_menu;
}