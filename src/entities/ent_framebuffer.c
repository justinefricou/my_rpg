/*
** EPITECH PROJECT, 2020
** ent_music
** File description:
** ent_music
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

dg_entity_t *ent_framebuffer(sfVector2f pos, sfVector2i size)
{
    dg_entity_t *entity = dg_entity_create("framebuffer");

    dg_entity_add_component(entity, dg_cpt_pos(pos.x, pos.y));
    dg_entity_add_component(entity, cpt_framebuffer(size.x, size.y));
    return entity;
}