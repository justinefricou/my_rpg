/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** event function
*/

#include "libdragon.h"
#include "general_data.h"

#ifndef INTRO_H_
#define INTRO_H_

typedef struct sprite {
    dg_entity_t *entity;
    sfVector2f *pos;
    sfVector2f *size;
} sprite_t;


typedef struct data {
    float clock;
    sprite_t gun;
    dg_scene_t *layer;
} data_t;

#endif /*INTRO_H_*/
