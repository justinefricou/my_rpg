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

parameters_t *ins_set_dialog(instruction_t *instruction, int *i,
    general_data_t *gd, int *len)
{
    parameters_t *param = malloc(sizeof(parameters_t) * 2);
    parameters_t *text_param = instruction[*i].parameters;

    param[0].type = INSTRUCTIONS;
    param[0].parameters.i = ins_set_intern(instruction, i, gd);
    param[1].type = VOID;
    *len = 1;
    return param;
}

intern_t *ins_ini_dialog(void)
{
    return NULL;
}

int ins_act_dialog(intern_t *intern, self_data_t data,
    general_data_t *gd)
{
    return 1;
}

void ins_end_dialog(intern_t *intern)
{

}