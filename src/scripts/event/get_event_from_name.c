/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** script player controller
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "tilemap.h"
#include "general_data.h"
#include "epitech_tools.h"
#include "event.h"
#include "instructions.h"
#include "script_event_data.h"

void get_event_from_name(char *name, general_data_t *gd, data_t *data)
{
    data->intern.script = NULL;
    data->intern.reader.len = 0;
    for (int i = 0; i < gd->event_manager.event_len; i++)
        if (!dg_strcmp(gd->event_manager.events[i].name, name)) {
            data->intern.script = gd->event_manager.events[i].parameters;
            data->intern.reader.len = gd->event_manager.events[i].len;
            return;
        }
}