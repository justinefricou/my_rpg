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

static const float SHAPE_WIDTH = 32 * 3 * 16 / 4;
static const float SHAPE_HEIGHT = 20 * 3 * 16 / 3;

static void inventory_update_rect(data_t *data, general_data_t *dt)
{
    sfVector2f pos = {10, 10};

    pos.x += (data->selector.select % 4) * SHAPE_WIDTH;
    pos.y += ((data->selector.select - 4 * data->selector.defilement) / 4)
        * SHAPE_HEIGHT;
    sfRectangleShape_setPosition(data->selector.selector, pos);
    if (dt->inventory.len <= 0)
        sfRectangleShape_setSize(data->selector.selector, (sfVector2f){0, 0});
    else
        sfRectangleShape_setSize(data->selector.selector,
            (sfVector2f){SHAPE_WIDTH - 20, SHAPE_HEIGHT - 20});
}

static void inv_update_defilement(data_t *data)
{
    while (data->selector.select - data->selector.defilement * 4 >= 12)
        data->selector.defilement++;
    while (data->selector.select - data->selector.defilement * 4 < 0)
        data->selector.defilement--;
}

void inventory_update_selector(data_t *data, general_data_t *gd)
{
    inv_update_defilement(data);
    inventory_update_rect(data, gd);
    if (data->selector.select > gd->inventory.len)
        data->selector.select = gd->inventory.len;
}