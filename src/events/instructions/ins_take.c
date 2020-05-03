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
#include "give.h"

parameters_t *ins_set_take(instruction_t *instruction, int *i,
    general_data_t *gd, int *len)
{
    parameters_t *param = malloc(sizeof(parameters_t) * 3);
    parameters_t *text_param = instruction[*i].parameters;

    param[0].type = STRING;
    param[0].parameters.s = text_param[0].parameters.s;
    param[1].type = INT;
    param[1].parameters.n = my_atoi(text_param[1].parameters.s);
    param[2].type = NONE;
    *len = 2;
    return param;
}

intern_t *ins_ini_take(intern_t *prev, general_data_t *gd)
{
    return NULL;
}

int ins_act_take(intern_t *intern, self_data_t data,
    dg_window_t *w, sfTime dt)
{
    general_data_t *gd = w->general_data;
    parameters_t *params = intern->script[intern->reader.progress].parameters;
    int test = 0;

    test += (!test) ? give_player(gd, params, -1) : 0;
    test += (!test) ? give_obj(gd, params, -1) : 0;
    return 1;
}

void ins_end_take(intern_t *intern)
{
    return;
}