/*
** EPITECH PROJECT, 2020
** background_menu
** File description:
** background_menu
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

dg_entity_t *ent_sprite(dg_spritesheet_t *sheet, int id,
    float scale, sfVector2f pos)
{
    dg_entity_t *background_menu = dg_entity_create("sprite");

    dg_entity_add_component(background_menu, dg_cpt_pos(pos.x, pos.y));
    dg_entity_add_component(background_menu, cpt_scale(scale, scale));
    dg_entity_add_component(background_menu, cpt_sprite(
       sheet, id));
    return background_menu;
}
