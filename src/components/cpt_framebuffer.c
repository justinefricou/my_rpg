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
    dg_framebuffer_t *scale = (float *)(data);

    dg_framebuffer_destroy(scale);
}

dg_component_t *cpt_framebuffer(int width, int height)
{
    void (*destroy)(void *) = &component_destroy;
    dg_framebuffer_t *fb = dg_framebuffer_create(width, height);
    dg_component_t *component = 0;

    component = dg_component_create("framebuffer", fb, destroy);
    return component;
}