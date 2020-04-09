/*
** EPITECH PROJECT, 2020
** sys_camera
** File description:
** sys_camera
*/

#include <stdlib.h>
#include "dg_component.h"
#include "tilemap.h"
#include "ecs.h"

void sys_camera(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_entity_t *camera = dg_get_entity(*entities, "camera");
    dg_entity_t *sprite = dg_get_entity(*entities, "map");
    dg_entity_t *player = dg_get_entity(*entities, "player");
    tilemap_t *sprite_map = (tilemap_t *)
        (dg_entity_get_component(sprite, "tilemap"));
    sfVector2f *s_scale = (sfVector2f *)
        (dg_entity_get_component(sprite, "scale"));
    sfVector2f *c_pos = (sfVector2f *)(dg_entity_get_component(camera, "pos"));
    sfVector2f *s_pos = (sfVector2f *)(dg_entity_get_component(player, "pos"));
    sfVector2f map_size =
        {sprite_map->width * sprite_map->sheet->x * s_scale->x,
        sprite_map->height * sprite_map->sheet->y * s_scale->y};

    if (!camera || sprite_map == NULL)
        return;
    if (s_pos->x > 960 && s_pos->x < map_size.x + 320)
        c_pos->x = s_pos->x - 960;
    if (s_pos->y > 540 && s_pos->y < map_size.y + 180)
        c_pos->y = s_pos->y - 540;
}