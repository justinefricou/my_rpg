/*
** EPITECH PROJECT, 2020
** cpt_particle
** File description:
** cpt_particle
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "ecs.h"
#include "particle.h"

static void component_destroy(void *data)
{
    sfVector2f *d = (sfVector2f *)(data);
}

dg_component_t *cpt_particle(float x, float y, int type)
{
    void (*destroy)(void *) = &component_destroy;
    particle_system_t *particle = particle_create((sfVector2f){x, y});
    dg_component_t *component = dg_component_create
        ("particle", particle, destroy);

    particle_set_type(particle, type);
    return component;
}