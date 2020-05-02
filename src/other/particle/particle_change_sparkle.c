/*
** EPITECH PROJECT, 2020
** cpt_scale
** File description:
** cpt_scale
*/

#include <stdlib.h>
#include "libdragon.h"
#include "particle.h"

void sparkle_change_density(particle_system_t *ps, float density)
{
    particle_sparkle_t *intern = NULL;

    if (ps->type != SPARKLE)
        return;
    intern = ps->data;
    intern->density = density;
}

void sparkle_change_dispersion(particle_system_t *ps, sfVector2i dispersion)
{
    particle_sparkle_t *intern = NULL;

    if (ps->type != SPARKLE)
        return;
    intern = ps->data;
    intern->dispersion = dispersion;
}

void sparkle_change_dispersion_type(particle_system_t *ps,
    int dispersion_type)
{
    particle_sparkle_t *intern = NULL;

    if (ps->type != SPARKLE)
        return;
    intern = ps->data;
    intern->dispersion_type = dispersion_type;
}

void sparkle_change_size(particle_system_t *ps, int size)
{
    particle_sparkle_t *intern = NULL;

    if (ps->type != SPARKLE)
        return;
    intern = ps->data;
    intern->size = size;
}

void sparkle_change_duration(particle_system_t *ps, float duration)
{
    particle_sparkle_t *intern = NULL;

    if (ps->type != SPARKLE)
        return;
    intern = ps->data;
    intern->duration = duration;
}