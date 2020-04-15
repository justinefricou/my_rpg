/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** sprite
*/

#ifndef SPRITE_H_
#define SPRITE_H_

#include "libdragon.h"

typedef struct sprite
{
    dg_spritesheet_t *sheet;
    int id;
} sprite_t;

#endif /* !SPRITE_H_ */