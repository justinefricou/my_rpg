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
#include "give.h"

parameters_t *ins_set_give(instruction_t *instruction, int *i,
    general_data_t *gd)
{
    parameters_t *param = malloc(sizeof(parameters_t) * 3);
    parameters_t *text_param = instruction[*i].parameters;

    param[0].type = STRING;
    param[0].parameters.s = text_param[0].parameters.s;
    param[1].type = INT;
    param[1].parameters.n = atoi(text_param[1].parameters.s);
    param[2].type = NONE;
    return param;
}

intern_t *ins_ini_give(void)
{
    return NULL;
}

int ins_act_give(intern_t *intern, self_data_t data,
    general_data_t *gd)
{
    parameters_t *params = intern->script[intern->reader.progress].parameters;
    int test = 0;
    
    test += give_obj(gd, params);
    test += (!test) ? give_player(gd, params) : 0;
    return 1;
}

void ins_end_give(intern_t *intern)
{
    return;
}