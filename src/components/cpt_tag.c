/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** tag component
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

static void component_destroy(void *data)
{
    (void) data;
}

dg_component_t *cpt_tag(char *tag)
{
    dg_cpt_destroy_t destroy = &component_destroy;
    dg_component_t *component = dg_component_create("tag",
        tag, destroy);

    return component;
}
