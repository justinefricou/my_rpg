/*
** EPITECH PROJECT, 2020
** my rpg
** File description:
** transform
*/

#include <stdlib.h>
#include "libdragon.h"
#include "transform.h"

transform_t transform(float x, float y, float sx, float sy)
{
    transform_t tr = {0};

    tr.pos.x = x;
    tr.pos.y = y;
    tr.scale.x = sx;
    tr.scale.y = sy;
    return tr;
}

transform_t transformm(sfVector2f pos, sfVector2f scale)
{
    transform_t tr = {0};

    tr.pos = pos;
    tr.scale = scale;
    return tr;
}