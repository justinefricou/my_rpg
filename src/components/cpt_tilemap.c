/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** tilemap component
*/

#include <stdlib.h>
#include "tilemap.h"
#include "dg_component.h"
#include "ecs.h"

static void component_destroy(void *data)
{
    tilemap_t *tm = (tilemap_t *) data;

    tilemap_destroy(tm);
}

dg_component_t *cpt_tilemap(int **map, dg_spritesheet_t *sheet,
    int free_map_on_destroy)
{
    dg_cpt_destroy_t destroy = &component_destroy;
    tilemap_t *tm = tilemap_create(map, sheet,
        free_map_on_destroy);
    dg_component_t *component = dg_component_create("tilemap",
        tm, destroy);

    return component;
}
