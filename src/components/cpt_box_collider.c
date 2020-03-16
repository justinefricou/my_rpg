/*
** EPITECH PROJECT, 2020
** cpt_box_collider
** File description:
** cpt_box_collider
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "ecs.h"

static void component_destroy(void *data)
{
    sfIntRect *box_collider = (sfIntRect *)(data);

    free(box_collider);
}

dg_component_t *cpt_box_collider(float left, float top
    , float height, float width)
{
    void (*destroy)(void *) = &component_destroy;
    sfIntRect *box_collider = 0;
    dg_component_t *component = 0;

    box_collider = malloc(sizeof(sfIntRect));
    box_collider->left = left;
    box_collider->top = top;
    box_collider->height = height;
    box_collider->width = width;
    component = dg_component_create("box_collider", box_collider, destroy);
    return component;
}