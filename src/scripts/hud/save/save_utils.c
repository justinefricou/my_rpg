/*
** EPITECH PROJECT, 2020
** script_monster
** File description:
** script player controller
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "hud/hud_save.h"

void save_update_position(data_t *data)
{
    int select = data->select;
    sfVector2f pos = {-5, 165 + select * 270};

    sfRectangleShape_setPosition(data->selector, pos);
}