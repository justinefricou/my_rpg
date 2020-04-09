/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** tilemap
*/

#include <stdlib.h>
#include "libdragon.h"
#include "tilemap.h"
#include "transform.h"

void tilemap_change_map(tilemap_t *tm, int **map, dg_spritesheet_t *sheet)
{
    if (!map)
        return;
    for (tm->height = 0; map[tm->height]; tm->height++);
    for (tm->width = 0; map[0][tm->width] != -1; tm->width++);
    tm->map = map;
    if (sheet)
        tm->sheet = sheet;
}

tilemap_t *tilemap_create(int **map, dg_spritesheet_t *sheet,
    int free_map_on_destroy)
{
    tilemap_t *tm = malloc(sizeof(tilemap_t));
    if (!map || !sheet) {
        free(tm);
        return NULL;
    }
    tilemap_change_map(tm, map, sheet);
    tm->free_map_on_destroy = free_map_on_destroy;
    return tm;
}

tilemap_t *tilemap_destroy(tilemap_t *tm)
{
    if (!tm)
        return NULL;
    if (tm->free_map_on_destroy) {
        for (int i = 0; tm->map[i]; i++)
            free(tm->map[i]);
        free(tm->map);
    }
    free(tm);
}

void tilemap_draw_display(tilemap_t *tm, transform_t transform,
    sfVector2f camera, dg_window_t *w)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f new_pos = transform.pos;

    if (!tm)
        return;
    sfSprite_setScale(sprite, transform.scale);
    for (int y = 0; y < tm->height; y++) {
        new_pos.x = transform.pos.x;
        for (int x = 0; x < tm->width; x++) {
            sfSprite_setPosition(sprite, new_pos);
            (tm->map[y][x] > 0) ? 
                dg_spritesheet_to_sprite(tm->sheet, sprite,
                    tm->map[y][x] - 1) : NULL;
            dg_camera_render(camera, sprite,  w);
            new_pos.x += tm->sheet->x * transform.scale.x;
        }
        new_pos.y += tm->sheet->y * transform.scale.y;
    }
    sfSprite_destroy(sprite);
}

int tilemap_collide_test(tilemap_t *tm, transform_t transform,
    sfVector2f target)
{
    int x = (target.x - transform.pos.x) / (tm->sheet->x * transform.scale.x);
    int y = (target.y - transform.pos.y) / (tm->sheet->y * transform.scale.y);

    if (x > tm->width || x < 0 || y > tm->height || y < 0)
        return 0;
    if (tm->map[y][x] > 0)
        return tm->map[y][x];
    return 0;
}