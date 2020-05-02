/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** system : animator
*/

#include <stdlib.h>
#include "libdragon.h"
#include "particle.h"

static sfVector2f dg_pos_to_camera(sfVector2f pos, sfVector2f camera)
{
    return (sfVector2f) {pos.x - camera.x, pos.y - camera.y};
}

void sys_particle(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_entity_t *camera = dg_get_entity(*entities, "camera");
    sfVector2f *c_pos = (sfVector2f *)(dg_entity_get_component(camera, "pos"));
    particle_system_t *ps = (particle_system_t *)
        (dg_entity_get_component(entity, "particle"));
    sfVector2f *pos = (sfVector2f *)
        (dg_entity_get_component(entity, "pos"));
    sfVector2f npos = {0};

    if (!dg_system_require(entity, 2, "particle", "pos") || !camera)
        return;
    npos = dg_pos_to_camera(*pos, *c_pos);
    particle_calcul_update(ps, dt);
    dg_framebuffer_update(ps->fb, w->window, npos.x, npos.y);
}
