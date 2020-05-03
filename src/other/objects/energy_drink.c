/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** objects
*/

#include "object.h"
#include "libdragon.h"
#include "general_data.h"

static void e_drink_action(dg_window_t *w)
{
    general_data_t *gd = w->general_data;

    gd->player.pm.x += 10;
    if (gd->player.pm.x > gd->player.pm.y)
        gd->player.pm.x = gd->player.pm.y;
}

object_t energy_drink(void)
{
    object_t obj = {0};

    obj.name = "energy_drink";
    obj.description = "Restores some of your energy.\n+10pm";
    obj.icon_id = 2;
    obj.consomable = 1;
    obj.action = &e_drink_action;
    obj.price = 8;
    return obj;
}