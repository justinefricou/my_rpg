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

    for (len = 0; text_param[len].type != VOID; len++);
    param = malloc(sizeof(parameters_t) * (len + 2));
    for (int i = 0; i < len; i++)
        param[i] = set_from_calcul(text_param[i].parameters.s, gd);
    param[len].type = INSTRUCTIONS;
    param[len].parameters.i = ins_set_intern(instruction, i, gd);
    param[len + 1].type = VOID;
    *rlen = len;
    return param;
}

intern_t *ins_ini_if(intern_t *prev)
{
    parameters_t *params = prev->script[prev->reader.progress].parameters;
    int len = prev->script[prev->reader.progress].len;
    intern_t *intern = malloc(sizeof(intern_t));

    intern->dialog = prev->dialog;
    intern->script = params[len].parameters.i;
    intern->reader.activation = 0;
    intern->reader.end = 0;
    intern->reader.active = 0;
    intern->reader.progress = 0;
    return intern;
}

int ins_act_if(intern_t *intern, self_data_t data,
    dg_window_t *w)
{
    parameters_t *params = intern->script[intern->reader.progress].parameters;
    int len = intern->script[intern->reader.progress].len;
    int condition = 1;

    if (!intern->intern->reader.end) {
        condition = calcul_condition(params, 0, len, w->general_data);
        if (!condition)
            return 1;
        intern->intern->reader.activation = 1;
        event_launch(intern->intern);
        intern->intern->reader.end = 1;
    } else {
        event_active(intern->intern, data, w);
        if (intern->intern->reader.active == 0) {
            return 1;
        }
    }
    return 0;
}

void ins_end_if(intern_t *intern)
{
    free(intern->intern);
}