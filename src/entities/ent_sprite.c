/*
** EPITECH PROJECT, 2020
** background_menu
** File description:
** background_menu
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

dg_entity_t *ent_sprite(int id, float scale, float x, float y)
{
    dg_entity_t *background_menu = dg_entity_create("sprite");

    dg_entity_add_component(background_menu, dg_cpt_pos(x, y));
    dg_entity_add_component(background_menu, cpt_scale(scale, scale));
    dg_entity_add_component(background_menu, cpt_spritesheet(
        dg_ressources_get_spritesheet_by_name("background_menu")));
    return background_menu;
}
