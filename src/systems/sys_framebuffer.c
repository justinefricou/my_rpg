/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** system : animator
*/

#include <stdlib.h>
#include "libdragon.h"
#include "particle.h"

void sys_framebuffer(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_entity_t *camera = dg_get_entity(*entities, "camera");
    sfVector2f *c_pos = (sfVector2f *)(dg_entity_get_component(camera, "pos"));
    dg_framebuffer_t *fb = (dg_framebuffer_t *)
        (dg_entity_get_component(entity, "framebuffer"));
    sfVector2f *pos = (sfVector2f *)
        (dg_entity_get_component(entity, "pos"));
    sfVector2f npos = {0};

    if (!dg_system_require(entity, 2, "framebuffer", "pos") || !camera)
        return;
    npos = (sfVector2f) {pos->x - c_pos->x, pos->y - c_pos->y};
    dg_framebuffer_update(fb, w->window, npos.x, npos.y);
}
