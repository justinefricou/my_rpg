/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** color component
*/

#include <stdlib.h>
#include "dragon/dg_component.h"
#include "ecs.h"

static void component_destroy(void *data)
{
    sfColor *id = (sfColor *) data;

    free(id);
}

dg_component_t *cpt_color(sfColor color)
{
    dg_cpt_destroy_t destroy = &component_destroy;
    sfColor *ccolor = malloc(sizeof(sfColor));
    dg_component_t *component = dg_component_create("color",
        ccolor, destroy);

    *ccolor = color;
    return component;
}
