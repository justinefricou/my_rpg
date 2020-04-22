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

static const char *TYPE_STR[9] = {
    "INT",
    "STRING",
    "CHAR",
    "FLOAT",
    "INSTRUCTIONS",
    "VARIABLE",
    "CALCUL",
    "EQUALITY",
    "UNION"
};

int type_from_str(char *text)
{
    for (int i = 0; i < 5; i++)
        if (!dg_strcmp(text, TYPE_STR[i]))
            return i;
    return 0;
}