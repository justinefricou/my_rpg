/*
** EPITECH PROJECT, 2020
** dg_cpt_spritesheet
** File description:
** dg_cpt_spritesheet
*/

#include <stdlib.h>
#include "dragon/dg_component.h"
#include "ecs.h"
#include "sprite.h"

static void component_destroy(void *data)
{
    free(data);
}

dg_component_t *cpt_sprite(dg_spritesheet_t *sheet, int id)
{
    dg_cpt_destroy_t destroy = &component_destroy;
    sprite_t *sprite = malloc(sizeof(sprite_t));
    dg_component_t *component = dg_component_create("sprite",
        sprite, destroy);
    sprite->id = id;
    sprite->sheet = sheet;
    return component;
}
