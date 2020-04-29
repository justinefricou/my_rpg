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

static char *copy_name(char *name)
{
    int len = my_strlen(name);
    char *result = malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len; i++)
        result[i] = name[i];
    result[len] = '\0';
    return result;
}

int add_variable(general_data_t *gd, char *name)
{
    variable_t *new = malloc(sizeof(variable_t)
        * (gd->event_manager.var_len + 1));

    for (int i = 0; i < gd->event_manager.var_len; i++)
        new[i] = gd->event_manager.var[i];
    new[gd->event_manager.var_len].name = copy_name(name);
    new[gd->event_manager.var_len].data = 0;
    if (gd->event_manager.var)
        free(gd->event_manager.var);
    gd->event_manager.var = new;
    gd->event_manager.var_len++;
    return gd->event_manager.var_len - 1;
}

int variable_to_int(char *name, general_data_t *gd)
{
    for (int i = 0; i < gd->event_manager.var_len; i++) {
        if (!dg_strcmp(name, gd->event_manager.var[i].name))
            return i;
    }
    return add_variable(gd, name);
}