/*
** EPITECH PROJECT, 2020
** cpt_scale
** File description:
** cpt_scale
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "ecs.h"

static void component_destroy(void *data)
{
    sfVector2f *scale = (sfVector2f *)(data);

    free(scale);
}

dg_component_t *cpt_scale(float x, float y)
{
    void (*destroy)(void *) = &component_destroy;
    sfVector2f *scale = 0;
    dg_component_t *component = 0;

    scale = malloc(sizeof(sfVector2f));
    scale->x = x;
    scale->y = y;
    component = dg_component_create("scale", scale, destroy);
    return component;
}