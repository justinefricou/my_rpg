/*
** EPITECH PROJECT, 2020
** cpt_scale
** File description:
** cpt_scale
*/

#include <stdlib.h>
#include "libdragon.h"
#include "particle.h"

void particle_set_none(particle_system_t *ps)
{
    if (ps->type != PARTICLE_NONE)
        return;
    free(ps->data);
    free(ps->fb);
    ps->fb = NULL;
    ps->data = NULL;
    ps->clock = 0;
}

void particle_set_sparkle(particle_system_t *ps)
{
    particle_sparkle_t *intern = NULL;

    if (ps->type != SPARKLE)
        return;
    intern = malloc(sizeof(particle_sparkle_t));
    intern->density = 0.001;
    intern->dispersion = (sfVector2i) {200, 200};
    intern->dispersion_type = ROUND;
    intern->size = 5;
    intern->duration = 2;
    ps->data = intern;
    sparkle_force_update(ps);
}

void particle_set_rain(particle_system_t *ps)
{
    particle_rain_t *intern = NULL;

    if (ps->type != RAIN)
        return;
    intern = malloc(sizeof(particle_rain_t));
    intern->density = 0.001;
    intern->dispersion = (sfVector2i) {200, 200};
    intern->direction = 2;
    intern->size = (sfVector2i) {1, 3};
    intern->speed = 1;
    ps->data = intern;
    rain_force_update(ps);
}