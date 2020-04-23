/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** objects
*/

#include "object.h"
#include "libdragon.h"
#include "general_data.h"

static void calming_action(dg_window_t *w)
{
    general_data_t *gd = w->general_data;

    gd->player.pv.x += 10;
    if (gd->player.pv.x > gd->player.pv.y)
        gd->player.pv.x = gd->player.pv.y;
}

object_t calming(void)
{
    object_t obj = {0};

    obj.name = "calming_pills";
    obj.description = "Reduce your stress.\n+10pv";
    obj.icon_id = 1;
    obj.consomable = 1;
    obj.action = &calming_action;
    obj.price = 10;
    return obj;
}