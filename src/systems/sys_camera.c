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
    dg_spritesheet_t *sprite_map = (dg_spritesheet_t *)
        (dg_entity_get_component(sprite, "spritesheet"));
    sfVector2f *c_pos = (sfVector2f *)(dg_entity_get_component(camera, "pos"));
    sfVector2i s_pos = sfMouse_getPositionRenderWindow(w->window);

    if (!camera || sprite_map == NULL)
        return;
    if (s_pos.x > 1800 && c_pos->x < sprite_map->x - 1920) {
        c_pos->x += 1;
    } else if (s_pos.x < 120 && c_pos->x > 0) {
        c_pos->x -= 1;
    }
    c_pos->y = 0;
}