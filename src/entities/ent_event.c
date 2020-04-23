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
    dg_entity_t *entity = dg_entity_create("event");
    void *idata[3] = {&data, gd, entity};

    cpt_script(&scp_event_init, &scp_event_loop, &scp_event_end, idata);
    return entity;
}
