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

parameters_t *ins_set_set(instruction_t *instruction, int *i,
    general_data_t *gd, int *rlen)
{
    parameters_t *param = 0;
    int len = instruction[*i].len;
    parameters_t *text_param = instruction[*i].parameters;

    param = malloc(sizeof(parameters_t) * (len + 1));
    param[0].type = INT;
    param[0].parameters.n = variable_to_int(text_param[0].parameters.s, gd);
    for (int i = 1; i < len; i++)
        param[i] = set_from_calcul(text_param[i].parameters.s, gd);
    param[len].type = VOID;
    *rlen = len;
    return param;
}

intern_t *ins_ini_set(intern_t *prev)
{
    return NULL;
}

int ins_act_set(intern_t *intern, self_data_t data,
    dg_window_t *w)
{
    general_data_t *gd = w->general_data;
    parameters_t *params = intern->script[intern->reader.progress].parameters;
    int len = intern->script[intern->reader.progress].len;
    int *var = &(gd->event_manager.var[params[0].parameters.n].data);

    *var = event_calculate(&(params[1]), gd, len - 1);
    return 1;
}

void ins_end_set(intern_t *intern)
{

}