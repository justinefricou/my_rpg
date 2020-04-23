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

void event_active(intern_t *data, self_data_t self, general_data_t *gd)
{
    if (!data->reader.active)
        return;
    while (data->script[data->reader.progress].keycode != NONE &&
        key_active[data->script[data->reader.progress].keycode]
        (data, self, gd)) {
        key_end[data->script[data->reader.progress].keycode](data);
        data->reader.progress++;
    }
    if (data->script[data->reader.progress].keycode == NONE) {
        data->reader.active = 0;
    }
}

void event_launch(intern_t *data)
{
    if (data->reader.activation) {
        data->reader.progress = 0;
        data->reader.active = 1;
        data->reader.activation = 0;
        data->reader.end = 0;
        data->intern = key_init[data->script[data->reader.progress].keycode]();
    }
}