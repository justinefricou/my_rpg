/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** background_menu
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "general_data.h"
#include "libmy.h"
#include "epitech_tools.h"
#include "instructions.h"

void *get_variable(variable_t *var, int i)
{
    if (var[i].data.type == INT || var[i].data.type == CALCUL
        || var[i].data.type == EQUALITY || var[i].data.type == UNION
        || var[i].data.type == VARIABLE)
        return &var[i].data.parameters.n;
    switch (var[i].data.type)
    {
        case FLOAT:
            return &var[i].data.parameters.f;
        case CHAR:
            return &var[i].data.parameters.c;
        case STRING:
            return &var[i].data.parameters.s;
        case INSTRUCTIONS:
            return &var[i].data.parameters.i;
    }
    
}

void set_variable(variable_t *var, int i, void *data)
{
    var[i].data.parameters.n = 
        (var[i].data.type == INT || var[i].data.type == VARIABLE
        || var[i].data.type == EQUALITY || var[i].data.type == CALCUL
        || var[i].data.type == UNION) ?
        *((int *)data) : 0;
    var[i].data.parameters.f = (var[i].data.type == FLOAT) ?
        *((float *)data) : var[i].data.parameters.f;
    var[i].data.parameters.c = (var[i].data.type == CHAR) ?
        *((char *)data) : var[i].data.parameters.c;
    var[i].data.parameters.s = (var[i].data.type == STRING) ?
        *((char **)data) : var[i].data.parameters.s;
    var[i].data.parameters.i = (var[i].data.type == INSTRUCTIONS) ?
        *((instruction_t **)data) : var[i].data.parameters.i;
}

static void init_variable(variable_t *new, int i)
{
    new[i].data.parameters.c = 0;
    new[i].data.parameters.f = 0;
    new[i].data.parameters.i = 0;
    new[i].data.parameters.n = 0;
    new[i].data.parameters.s = 0;
}

int add_variable(general_data_t *gd, char *name, int type)
{
    variable_t *new = malloc(sizeof(variable_t)
        * (gd->event_manager.var_len + 1));
    
    for (int i = 0; i < gd->event_manager.var_len; i++)
        new[i] = gd->event_manager.var[i];
    new[gd->event_manager.var_len].name = name;
    new[gd->event_manager.var_len].data.type = type;
    init_variable(new, gd->event_manager.var_len);
    gd->event_manager.var_len++;
    return gd->event_manager.var_len - 1;
}

int variable_to_int(char *name, general_data_t *gd, char *type)
{
    for (int i = 0; i < gd->event_manager.var_len; i++) {
        if (!dg_strcmp(name, gd->event_manager.var[i].name))
            return i;
    }
    return add_variable(gd, name, type_from_str(type));
}