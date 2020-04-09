/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** tilemap
*/

#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "libdragon.h"

typedef struct transform
{
    sfVector2f pos;
    sfVector2f scale;
} transform_t;

transform_t transform(float x, float y, float sx, float sy);
transform_t transformm(sfVector2f pos, sfVector2f scale);

#endif /* !TRANSFORM_H_ */