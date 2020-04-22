/*
** EPITECH PROJECT, 2020
** script_monster
** File description:
** script player controller
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "hud/hud_inventory.h"

void inventory_active_slot(data_t *data, int id, int status)
{
    data->slots.slots[id].icon.entity->activated = status;
    data->slots.slots[id].name.entity->activated = status;
    data->slots.slots[id].quantity.entity->activated = status;
}