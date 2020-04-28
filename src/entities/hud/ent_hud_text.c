/*
** EPITECH PROJECT, 2020
** ent_map
** File description:
** ent_map
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"

int **create_hud_box(int sx, int sy, int style);

dg_entity_t *ent_hud_text(char *text)
{
    int **map = create_hud_box(10, 4, 0);
}