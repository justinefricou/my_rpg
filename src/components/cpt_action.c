/*
** EPITECH PROJECT, 2020
** cpt_action
** File description:
** cpt_action
*/

#include <stdlib.h>
#include "dragon/dg_component.h"
#include "ecs.h"

static void component_destroy(void *data)
{
}

dg_component_t *cpt_action(void (*action)(dg_window_t *))
{
    void (*destroy)(void *) = &component_destroy;
    dg_component_t *component = dg_component_create("action", action, destroy);

    return component;
}