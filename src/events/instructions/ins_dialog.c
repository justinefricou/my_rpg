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

parameters_t *ins_set_dialog(instruction_t *instruction, int *i,
    general_data_t *gd)
{
    parameters_t *param = malloc(sizeof(parameters_t) * 2);
    parameters_t *text_param = instruction[*i].parameters;

    param[0].type = INSTRUCTIONS;
    param[0].parameters.i = ins_set_intern(instruction, i, gd);
    param[1].type = NONE;
    return param;
}