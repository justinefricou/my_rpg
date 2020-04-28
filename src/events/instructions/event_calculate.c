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

static int get_var_data(parameters_t params, general_data_t *gd)
{
    int result = 0;

    if (params.type == VARIABLE)
        return gd->event_manager.var[params.parameters.n].data;
    else
        return params.parameters.n;
}

int event_calculate(parameters_t *params, general_data_t *gd, int len)
{
    int result = get_var_data(params[0], gd);
    int tmp = 0;
    int type;

    for (int i = 1; i < len; i+= 2) {
        type = params[i].parameters.n;
        tmp = get_var_data(params[i + 1], gd);
        result += (type == PLUS) ? tmp : 0;
        result -= (type == MINUS) ? tmp : 0;
        result /= (type == DIVIDE) ? tmp : 1;
        result *= (type == MULTIPLY) ? tmp : 1;
    }
    return result;
}