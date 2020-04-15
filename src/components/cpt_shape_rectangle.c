/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** square shape
*/

#include <stdlib.h>
#include "dragon/dg_component.h"
#include "ecs.h"

static void component_destroy(void *data)
{
    sfRectangleShape *rs = (sfRectangleShape *)(data);

    sfRectangleShape_destroy(rs);
}

dg_component_t *cpt_shape_rectangle(sfVector2f pos, sfVector2f size,
    sfColor fill, sfColor outline)
{
    void (*destroy)(void *) = &component_destroy;
    sfRectangleShape *shape = sfRectangleShape_create();
    dg_component_t *component = dg_component_create("shape_rectangle",
        shape, destroy);

    sfRectangleShape_setPosition(shape, pos);
    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setFillColor(shape, fill);
    sfRectangleShape_setOutlineColor(shape, outline);
    return component;
}
