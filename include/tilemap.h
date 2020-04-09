/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** tilemap
*/

#ifndef TILEMAP_H_
#define TILEMAP_H_

#include "libdragon.h"
#include "transform.h"

typedef struct tilemap
{
    int **map;
    int width;
    int height;
    dg_spritesheet_t *sheet;
    int free_map_on_destroy;
} tilemap_t;

tilemap_t *tilemap_create(int **map, dg_spritesheet_t *sheet,
    int free_map_on_destroy);
tilemap_t *tilemap_destroy(tilemap_t *tm);
void tilemap_draw_display(tilemap_t *tm, transform_t transform,
    sfVector2f camera, dg_window_t *w);
int tilemap_collide_test(tilemap_t *tm, transform_t transform,
    sfVector2f target);
void tilemap_change_map(tilemap_t *tm, int **map, dg_spritesheet_t *sheet);

#endif /* !TOWER_DATA_H_ */