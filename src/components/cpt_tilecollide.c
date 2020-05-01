/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** tilemap component
*/

#include <stdlib.h>
#include "tilemap.h"
#include "dragon/dg_component.h"
#include "ecs.h"

static void component_destroy(void *data)
{
    tilemap_t *tm = (tilemap_t *) data;

    for (int i = 0; i < tm->height; i++) {
        free(tm->map[i]);
    }
    free(tm->map);
    tilemap_destroy(tm);
}

int **copy_map(int **map)
{
    int width = 0;
    int height = 0;
    int **copy_map = 0;

    for (width = 0; map[0][width] != -1; width++);
    for (height = 0; map[height]; height++);
    copy_map = malloc(sizeof(int *) * (height + 1));
    for (int i = 0; i < height; i++) {
        copy_map[i] = malloc(sizeof(int) * (width + 1));
        for (int x = 0; x <= width; x++)
            copy_map[i][x] = map[i][x];
    }
    copy_map[height] = NULL;
    return copy_map;
}

dg_component_t *cpt_tilecollide(int **map, dg_spritesheet_t *sheet,
    int free_map_on_destroy)
{
    dg_cpt_destroy_t destroy = &component_destroy;
    int **map_copy = copy_map(map);
    tilemap_t *tm = tilemap_create(map_copy, sheet,
        free_map_on_destroy);
    dg_component_t *component = dg_component_create("tilecollide",
        tm, destroy);

    return component;
}
