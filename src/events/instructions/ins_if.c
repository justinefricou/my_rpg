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

parameters_t *ins_set_if(instruction_t *instruction, int *i,
    general_data_t *gd, int *rlen)
{
    int len = 0;
    parameters_t *param = 0;
    parameters_t *text_param = instruction[*i].parameters;

    for (len = 0; text_param[len].type != NONE; len++);
    param = malloc(sizeof(parameters_t) * (len + 2));
    for (int i = 0; i < len; i++)
        param[i] = set_from_calcul(text_param[i].parameters.s, gd);
    param[len].type = INSTRUCTIONS;
    param[len].parameters.i = ins_set_intern(instruction, i, gd);
    param[len + 1].type = VOID;
    *rlen = len;
    return param;
}

intern_t *ins_ini_if(void)
{
    return NULL;
}

int ins_act_if(intern_t *intern, self_data_t data,
    general_data_t *gd)
{
    return 1;
}

void ins_end_if(intern_t *intern)
{

}