/*
** EPITECH PROJECT, 2020
** background_menu
** File description:
** background_menu
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "event.h"

dg_entity_t *ent_event(map_events_t data, general_data_t *gd)
{
    dg_entity_t *button = dg_entity_create("event");
    void *idata[2] = {&data, gd};

    //cpt_script();
    return button;
}
