/*
** EPITECH PROJECT, 2020
** cpt_scale
** File description:
** cpt_scale
*/

#include <stdlib.h>
#include "libdragon.h"
#include "particle.h"

static const particle_updater_t update[PARTICLE_TYPE_LEN] =
    {NULL, &particle_calcul_update_sparkle, NULL};

void particle_calcul_update_sparkle(particle_system_t *ps, sfTime dt)
{
    particle_sparkle_t *intern = ps->data;
    sfVector2u tmp = {0};
    sfColor tmp_color = {0};

    for (int i = 0; i < intern->nb; i++) {
        tmp = (sfVector2u)
            {intern->particles[i].pos.x, intern->particles[i].pos.y};
        tmp_color = ps->color;
        tmp_color.a = (intern->particles[i].clock / intern->duration) * 255;
        dg_fb_putcircle(ps->fb, tmp,intern->size , tmp_color);
        if (intern->particles[i].clock > intern->duration)
            intern->particles[i].clock = 0;
        intern->particles[i].clock += sfTime_asSeconds(dt);
    }
}

void particle_calcul_update(particle_system_t *ps, sfTime dt)
{
    dg_fb_fill(ps->fb, (sfColor) {0, 0, 0, 0});
    if (update[ps->type] != NULL) {
        update[ps->type](ps, dt);
    }
}