/*
** EPITECH PROJECT, 2020
** ent_map
** File description:
** ent_map
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

static const int top[1] = {2};
static const int center[1] = {59};
static const int bottom[1] = {116};
static const int small[1] = {26};

static void hud_box_set(int **map, int sx, int sy, int style)
{
    if (sy == 1) {
        for (int i = 0; i < sx; i++)
            map[0][i] = small[style];
        map[0][0] = small[style] - 1;
        map[0][sx - 1] = small[style] + 1;
        return;
    }
    for (int x = 0; x < sx; x++) {
        map[0][x] = top[style];
        map[sy - 1][x] = bottom[style];
    }
    for (int y = 0; y < sy; y++) {
        map[y][0] = center[style] - 1;
        map[y][sx - 1] = center[style] + 1;
    }
    map[0][0] = top[style] - 1;
    map[0][sx - 1] = top[style] + 1;
    map[sy - 1][0] = bottom[style] - 1;
    map[sy - 1][sx - 1] = bottom[style] + 1;
}

int **create_hud_box(int sx, int sy, int style)
{
    int **map = malloc(sizeof(int *) * (sy + 1));

    for (int i = 0; i < sy; i++) {
        map[i] = malloc(sizeof(int) * (sx + 1));
        for (int x = 0; x < sx; x++)
            map[i][x] = center[style];
        map[i][sx] = -1;
    }
    map[sy] = NULL;
    hud_box_set(map, sx, sy, style);
    return map;
}

dg_entity_t *ent_hud_box(int x, int y, int sx, int sy)
{
    dg_entity_t *background_menu = dg_entity_create("hud_box");
    int **map = create_hud_box(sx, sy, 0);

    dg_entity_add_component(background_menu, dg_cpt_pos(x, y));
    dg_entity_add_component(background_menu, cpt_scale(3, 3));
    dg_entity_add_component(background_menu, cpt_tilemap(map,
        dg_ressources_get_spritesheet_by_name("hud"), 1));
    return background_menu;
}