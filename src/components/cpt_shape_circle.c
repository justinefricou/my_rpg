/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** shape circle
*/

#include <stdlib.h>
#include "dragon/dg_component.h"
#include "ecs.h"

static void component_destroy(void *data)
{
    sfCircleShape *rs = (sfCircleShape *)(data);

    sfCircleShape_destroy(rs);
}

dg_component_t *cpt_shape_circle(sfVector2f pos, int size,
    sfColor fill, sfColor outline)
{
    void (*destroy)(void *) = &component_destroy;
    sfCircleShape *shape = sfCircleShape_create();
    dg_component_t *component = dg_component_create("shape_circle",
        shape, destroy);

    sfCircleShape_setPosition(shape, pos);
    sfCircleShape_setRadius(shape, size);
    sfCircleShape_setFillColor(shape, fill);
    sfCircleShape_setOutlineColor(shape, outline);
    return component;
}
