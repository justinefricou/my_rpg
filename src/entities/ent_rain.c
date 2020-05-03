/*
** EPITECH PROJECT, 2020
** ent_music
** File description:
** ent_music
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "particle.h"

dg_entity_t *ent_rain(rain_context_t context)
{
    dg_entity_t *entity = dg_entity_create("particle");
    dg_component_t *cpt = cpt_particle(0, 0, RAIN);
    particle_system_t *ps = cpt->data;
    particle_rain_t *intern = ps->data;

    intern->density = context.density;
    intern->direction = context.direction;
    intern->dispersion = context.dispersion;
    intern->size = context.size;
    intern->speed = context.speed;
    ps->color = context.color;
    rain_force_update(ps);
    dg_entity_add_component(entity, dg_cpt_pos(context.position.x,
        context.position.y));
    dg_entity_add_component(entity, cpt);
    return entity;
}