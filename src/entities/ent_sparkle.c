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

dg_entity_t *ent_sparkle(sparkle_context_t context)
{
    dg_entity_t *entity = dg_entity_create("particle");
    dg_component_t *cpt = cpt_particle(0, 0, SPARKLE);
    particle_system_t *ps = cpt->data;
    
    sparkle_change_size(ps, context.size);
    sparkle_change_density(ps, context.density);
    sparkle_change_duration(ps, context.duration);
    sparkle_change_dispersion_type(ps, context.dispersion_type);
    sparkle_change_dispersion(ps, context.dispersion);
    ps->color = context.color;
    sparkle_force_update(ps);
    dg_entity_add_component(entity, dg_cpt_pos(context.position.x,
        context.position.y));
    dg_entity_add_component(entity, cpt);
    return entity;
}