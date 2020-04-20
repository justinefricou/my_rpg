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

parameters_t *ins_set_for(instruction_t *instruction, int *i,
    general_data_t *gd)
{
    int len = 0;
    parameters_t *param = malloc(sizeof(parameters_t) * 4);
    parameters_t *text_param = instruction[*i].parameters;

    param[0] = set_from_calcul(text_param[0].parameters.s, gd);
    param[1] = set_from_calcul(text_param[1].parameters.s, gd);
    param[2].type = INSTRUCTIONS;
    param[2].parameters.i = ins_set_intern(instruction, i, gd);
    param[3].type = NONE;
    return param;
}