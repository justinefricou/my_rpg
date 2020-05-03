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
    float *scale = (float *)(data);

    free(scale);
}

dg_component_t *cpt_rot(float angle)
{
    void (*destroy)(void *) = &component_destroy;
    float *rot = 0;
    dg_component_t *component = 0;

    rot = malloc(sizeof(float));
    *rot = angle;
    component = dg_component_create("rot", rot, destroy);
    return component;
}