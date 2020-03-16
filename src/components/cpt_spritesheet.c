/*
** EPITECH PROJECT, 2020
** dg_cpt_spritesheet
** File description:
** dg_cpt_spritesheet
*/

#include <stdlib.h>
#include "dg_component.h"
#include "ecs.h"

static void component_destroy(void *data)
{
    (void) data;
}

dg_component_t *cpt_spritesheet(int id)
{
    dg_cpt_destroy_t destroy = &component_destroy;
    dg_spritesheet_t *sheet = dg_ressources_get_spritesheet(id);
    dg_component_t *component = dg_component_create("spritesheet",
        sheet, destroy);

    return component;
}
