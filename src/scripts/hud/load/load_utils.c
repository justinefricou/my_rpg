/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** load
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "hud/hud_load.h"

void load_update_position(data_t *data)
{
    int select = data->select;
    sfVector2f pos = {95, 165 + select * 270};

    sfRectangleShape_setPosition(data->selector, pos);
}