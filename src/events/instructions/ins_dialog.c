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
    int len = 0;
    parameters_t *param = malloc(sizeof(parameters_t) * 2);
    parameters_t *text_param = instruction[*i].parameters;

    for (len = 0; text_param[len].type != NONE; len++);
    param = malloc(sizeof(parameters_t) * len);
    param[0].type = INT;
    param[0].parameters.n = variable_to_int(text_param[1].parameters.s,
        gd, text_param[0].parameters.s);
    for (int i = 2; i < len; i++)
        param[i - 1] = set_from_calcul(text_param[i].parameters.s, gd);
    return param;
}