/*
** EPITECH PROJECT, 2020
** cpt_slot
** File description:
** cpt_slot
*/

#include <stdlib.h>
#include "dg_component.h"
#include "ecs.h"

static void component_destroy(void *data)
{
}

dg_component_t *cpt_action_slot(void (*action)(dg_entity_t *, dg_window_t *,
    dg_array_t **, sfTime))
{
    void (*destroy)(void *) = &component_destroy;
    dg_component_t *component = dg_component_create
        ("action_slot", action, destroy);

    return component;
}