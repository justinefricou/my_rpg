/*
** EPITECH PROJECT, 2020
** sys_camera
** File description:
** sys_camera
*/

#include <stdlib.h>
#include "dg_component.h"
#include "ecs.h"

void sys_camera(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_entity_t *camera = dg_get_entity(*entities, "camera");
    dg_entity_t *sprite = dg_get_entity(*entities, "map");
    dg_entity_t *player = dg_get_entity(*entities, "player");
    dg_spritesheet_t *sprite_map = (dg_spritesheet_t *)
        (dg_entity_get_component(sprite, "spritesheet"));
    sfVector2f *c_pos = (sfVector2f *)(dg_entity_get_component(camera, "pos"));
    sfVector2f *s_pos = (sfVector2f *)(dg_entity_get_component(player, "pos"));

    if (!camera || sprite_map == NULL)
        return;
    if (s_pos->x > 960 && s_pos->x < sprite_map->x + 320)
        c_pos->x = s_pos->x - 960;
    if (s_pos->y > 540 && s_pos->y < sprite_map->y + 180)
        c_pos->y = s_pos->y - 540;
}