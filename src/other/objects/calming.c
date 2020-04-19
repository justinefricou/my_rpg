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

    gd->player.pv += 10;
    if (gd->player.pv > gd->player.pv_max)
        gd->player.pv = gd->player.pv_max;
}

object_t calming(void)
{
    object_t obj = {0};

    obj.name = "calming pills";
    obj.description = "Reduce your stress.\n+10pv";
    obj.icon_id = 1;
    obj.consomable = 1;
    obj.action = &calming_action;
    return obj;
}