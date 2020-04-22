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
#include "event.h"
#include "epitech_tools.h"
#include "libmy.h"
#include "instructions.h"

static void sfc_equality(char *data, parameters_t *params)
{
    int result = 0;

    result = (!dg_strcmp("==", data)) ? 1 : result;
    result = (!dg_strcmp("<", data)) ? 2 : result;
    result = (!dg_strcmp(">", data)) ? 3 : result;
    result = (!dg_strcmp("<=", data)) ? 4 : result;
    result = (!dg_strcmp(">=", data)) ? 5 : result;
    result = (!dg_strcmp("!=", data)) ? 6 : result;
    if (result > 0) {
        params->type = EQUALITY;
        params->parameters.n = result - 1;
    }
}

static void sfc_calcul(char *data, parameters_t *params)
{
    int result = 0;

    result = (!dg_strcmp("+", data)) ? 1 : result;
    result = (!dg_strcmp("-", data)) ? 2 : result;
    result = (!dg_strcmp("/", data)) ? 3 : result;
    result = (!dg_strcmp("*", data)) ? 4 : result;
    if (result > 0) {
        params->type = CALCUL;
        params->parameters.n = result - 1;
    }
}

static void sfc_union(char *data, parameters_t *params)
{
    int result = 0;

    result = (!dg_strcmp("&&", data)) ? 1 : result;
    result = (!dg_strcmp("||", data)) ? 2 : result;
    result = (!dg_strcmp("!", data)) ? 3 : result;
    if (result > 0) {
        params->type = UNION;
        params->parameters.n = result - 1;
    }
}

static void sfc_number(char *data, parameters_t *params)
{
    if (((data[0] == '+' || data[0] == '-') &&
        (data[1] >= '0' && data[1] <= '9'))
        || (data[0] >= '0' && data[0] <= '9')) {
        params->type = UNION;
        params->parameters.n = my_atoi(data);
    }
}

parameters_t set_from_calcul(char *data, general_data_t *gd)
{
    parameters_t param = {0};

    param.type = NONE;
    sfc_equality(data, &param);
    sfc_calcul(data, &param);
    sfc_union(data, &param);
    sfc_number(data, &param);
    if (param.type == NONE) {
        param.type = VARIABLE;
        param.parameters.n = variable_to_int(data, gd);
    }
    return param;
}