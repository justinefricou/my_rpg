/*
** EPITECH PROJECT, 2020
** cpt_scale
** File description:
** cpt_scale
*/

#include <stdlib.h>
#include "libdragon.h"
#include "particle.h"

static const particle_setter_t type_initializer[PARTICLE_TYPE_LEN] =
    {&particle_set_none, &particle_set_sparkle, NULL};

void particle_set_type(particle_system_t *particle, int type)
{
    if (type > PARTICLE_TYPE_LEN)
        return;
    particle->type = type;
    particle->clock = 0;
    type_initializer[type](particle);
}

void particle_set_color(particle_system_t *particle, sfColor color)
{
    particle->color = color;
}

void particle_reset(particle_system_t *particle)
{
    particle->clock = 0;
}