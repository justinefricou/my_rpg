/*
** EPITECH PROJECT, 2020
** ent_map
** File description:
** ent_map
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

dg_entity_t *ent_map(char *sheet, float scale, int **map, int fmod)
{
    dg_entity_t *background_menu = dg_entity_create("map");

    dg_entity_add_component(background_menu, dg_cpt_pos(0, 0));
    dg_entity_add_component(background_menu, cpt_scale(scale, scale));
    dg_entity_add_component(background_menu, cpt_tilemap(map,
        dg_ressources_get_spritesheet_by_name(sheet), fmod));
    return background_menu;
}