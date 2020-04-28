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

parameters_t *ins_set_answer(instruction_t *instruction, int *i,
    general_data_t *gd, int *len)
{
    parameters_t *param = malloc(sizeof(parameters_t) * 3);
    parameters_t *text_param = instruction[*i].parameters;

    param[0].type = STRING;
    param[0].parameters.s = text_param[0].parameters.s;
    param[1].type = INSTRUCTIONS;
    param[1].parameters.i = ins_set_intern(instruction, i, gd);
    param[2].type = VOID;
    *len = 2;
    return param;
}

intern_t *ins_ini_answer(intern_t *prev)
{
    return NULL;
}

int ins_act_answer(intern_t *intern, self_data_t data,
    dg_window_t *w)
{
    return 1;
}

void ins_end_answer(intern_t *intern)
{

}