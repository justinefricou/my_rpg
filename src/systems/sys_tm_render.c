/*
** EPITECH PROJECT, 2020
** dg_cpt_spritesheet
** File description:
** dg_cpt_spritesheet
*/

#include <stdlib.h>
#include "dragon/dg_component.h"
#include "ecs.h"
#include "tilemap.h"
#include "transform.h"

void sys_tm_render(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_entity_t *camera = dg_get_entity(*entities, "camera");
    sfVector2f *c_pos = (sfVector2f *)(dg_entity_get_component(camera, "pos"));
    tilemap_t *tm = (tilemap_t *)
        (dg_entity_get_component(entity, "tilemap"));
    sfVector2f *pos = (sfVector2f *)
        (dg_entity_get_component(entity, "pos"));
    sfVector2f *scale = (sfVector2f *)
        (dg_entity_get_component(entity, "scale"));

    if (!tm || !pos || !camera)
        return;
    tilemap_draw_display(tm, transformm(*pos, *scale), *c_pos, w);
}