/*
** EPITECH PROJECT, 2020
** cpt_scale
** File description:
** cpt_scale
*/

#include <stdlib.h>
#include "libdragon.h"
#include "particle.h"

particle_system_t *particle_create(sfVector2f pos)
{
    particle_system_t *particle = malloc(sizeof(particle_system_t));

    particle->pos = pos;
    particle->color = (sfColor){255, 255, 255, 255};
    particle->type = PARTICLE_NONE;
    particle->fb = NULL;
    particle->data = NULL;
    particle->clock = 0;
    return particle;
}

void particle_destroy(particle_system_t *particle)
{
    if (particle->type != PARTICLE_NONE) {
        dg_framebuffer_destroy(particle->fb);
        free(particle->data);
    }
    free(particle);
}