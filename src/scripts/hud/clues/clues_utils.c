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
#include "hud/hud_clues.h"

static const char *CLUES_DESCRIPTION[CLUES_LEN][20] = {
    {
        "This is a clue, but the game hasn't been made",
        "so there is no clues ?",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "This is the end, please fullfill clues."
    }
};

void clues_update(data_t *data, dg_window_t *w)
{
    general_data_t *gd = w->general_data;

    for (int i = 0; i < 20; i++) {
        sfText_setString(data->text[i],
            CLUES_DESCRIPTION[gd->clues.list[data->select]][i]);
    }
}