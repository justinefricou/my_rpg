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
#include "hud/hud_inventory.h"
#include "general_data.h"

void inventory_update_weight(data_t *data, general_data_t *gd)
{
    char text[10] = {' '};
    int w = gd->inventory.stack.x;
    int m = gd->inventory.stack.y;

    text[0] = (w >= 100) ? '0' + w / 100 : ' ';
    text[1] = (w >= 10) ? '0' + (w / 10) % 10 : ' ';
    text[2] = '0' + w % 10;
    text[3] = ' ';
    text[4] = '/';
    text[5] = ' ';
    text[6] = (m >= 100) ? '0' + m / 100 : ' ';
    text[7] = (m >= 10) ? '0' + (m / 10) % 10 : ' ';
    text[8] = '0' + m % 10;
    text[9] = 0;
    sfText_setString(data->weight, text);
}