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

parameters_t *ins_set_move(instruction_t *instruction, int *i,
    general_data_t *gd, int *len)
{
    parameters_t *param = malloc(sizeof(parameters_t) * 4);
    parameters_t *text_param = instruction[*i].parameters;

    param[0].type = STRING;
    param[0].parameters.s = text_param[0].parameters.s;
    param[1].type = INT;
    param[1].parameters.n = my_atoi(text_param[1].parameters.s);
    param[2].type = INT;
    param[2].parameters.n = my_atoi(text_param[2].parameters.s);
    param[3].type = VOID;
    *len = 3;
    return param;
}

intern_t *ins_ini_move(intern_t *prev)
{
    return NULL;
}

int ins_act_move(intern_t *intern, self_data_t data,
    dg_window_t *w)
{
    return 1;
}

void ins_end_move(intern_t *intern)
{

}