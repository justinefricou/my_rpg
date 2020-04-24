/*
** EPITECH PROJECT, 2020
** sys_camera
** File description:
** sys_camera
*/

#include <stdlib.h>
#include "dragon/dg_component.h"
#include "tilemap.h"
#include "ecs.h"

void sys_camera(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_scene_t *scene = dg_scene_manager_get_scene("layer_bottom");
    dg_entity_t *camera = dg_get_entity(*entities, "camera");
    dg_entity_t *sprite = dg_get_entity(scene->entities, "map");
    dg_entity_t *player = dg_get_entity(*entities, "player");
    tilemap_t *sm = (tilemap_t *) (dg_entity_get_component(sprite, "tilemap"));
    sfVector2f *c_pos = (sfVector2f *)(dg_entity_get_component(camera, "pos"));
    sfVector2f *s_pos = (sfVector2f *)(dg_entity_get_component(player, "pos"));
    sfVector2f map_size =
        {sm->width * 16 * 3,
        sm->height * 16 * 3};

    if (!camera || sm == NULL)
        return;
    c_pos->x = s_pos->x - 960;
    c_pos->y = s_pos->y - 540;
    c_pos->x = (s_pos->x <= 960) ? 0 : c_pos->x;
    c_pos->x = (s_pos->x >= map_size.x - 960) ? map_size.x - 1920 : c_pos->x;
    c_pos->y = (s_pos->y <= 540) ? 0 : c_pos->y;
    c_pos->y = (s_pos->y >= map_size.y - 540) ? map_size.y - 1080 : c_pos->y;
}