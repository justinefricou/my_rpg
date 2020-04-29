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

int get_var_data(parameters_t params, general_data_t *gd);

static int is_calcul(parameters_t param) {
    if (param.type == INT || param.type == VARIABLE || param.type == CALCUL)
        return 1;
    return 0;
}

static int condition_calcul(parameters_t *params, general_data_t *gd, int *i)
{
    int result = get_var_data(params[*i], gd);
    int tmp = 0;
    int type;

    *i += 1;
    for (; is_calcul(params[*i]) && is_calcul(params[*i + 1]); *i += 2) {
        type = params[*i].parameters.n;
        tmp = get_var_data(params[*i + 1], gd);
        result += (type == PLUS) ? tmp : 0;
        result -= (type == MINUS) ? tmp : 0;
        result /= (type == DIVIDE) ? tmp : 1;
        result *= (type == MULTIPLY) ? tmp : 1;
        if (is_calcul(params[*i + 2])) {
            *i += 1;
            return result;
        }
    }
    return result;
}

int calcul_equality(int left, int right, int type)
{
    switch (type) {
        case EQUAL:
            return (left == right);
        case INEQUAL:
            return (left != right);
        case MORE:
            return (left > right);
        case LESS:
            return (left < right);
        case EMORE:
            return (left >= right);
        case ELESS:
            return (left <= right);
    }
    return 0;
}

int check_condition(int left, int right, sfVector2i link)
{
    int result = 0;

    if (link.x == EQUALITY) {
        result = calcul_equality(left, right, link.y);
    } else if (link.y == UNION) {
        switch (link.y) {
        case AND:
            return (left && right);
        case OR:
            return (left || right);
        }
    }
    return result;
}

int calcul_condition(parameters_t *params, int min,
    int max, general_data_t *gd)
{
    int i = min;
    int result = condition_calcul(params, gd, &i);
    int right = 0;
    sfVector2i link = {0};

    while (i < max) {
        link.x = params[i].type;
        link.y = params[i].parameters.n;
        i++;
        right = condition_calcul(params, gd, &i);
        result = check_condition(result, right, link);
    }
    return result;
}