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
#include "libmy.h"
#include "general_data.h"
#include "instructions.h"
#include "script_event_data.h"
#include "object.h"
#include "epitech_tools.h"

static const char *PLAYER_ATRIBUT[6] = {
    "PV", "PV_MAX", "PM",
    "PM_MAX", "XP", "MONEY"};

int give_obj(general_data_t *gd, parameters_t *params, int mul)
{
    int obj = object_get_id_by_name(gd->object_list.object,
        gd->object_list.len, params[0].parameters.s);

    if (obj >= 0) {
        add_to_inventory(gd, obj, params[1].parameters.n * mul);
        return 1;
    }
    return 0;
}

int give_player(general_data_t *gd, parameters_t *params, int mul)
{
    float *data[6] = {&(gd->player.pv.x), &(gd->player.pv.y),
        &(gd->player.pm.x), &(gd->player.pm.y), &(gd->player.xp.x)};

    for (int i = 0; i < 5; i++) {
        if (!dg_strcmp(PLAYER_ATRIBUT[i], params[0].parameters.s)) {
            *(data[i]) += params[1].parameters.n * mul;
            return 1;
        }
    }
    if (!dg_strcmp(PLAYER_ATRIBUT[5], params[0].parameters.s)) {
        gd->player.money += params[1].parameters.n * mul;
        return 1;
    }
    return 0;
}

int give_clues(general_data_t *gd, parameters_t *params, int mul)
{
    if (!dg_strcmp("CLUES", params[0].parameters.s)) {
        unlock_clue(gd, params[1].parameters.n);
        return 1;
    }
    return 0;
}