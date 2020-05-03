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
    float *rot;
} sprite_t;

typedef struct fb {
    dg_entity_t *entity;
    dg_framebuffer_t *fb;
} fb_t;

typedef struct data {
    float clock;
    sprite_t gun;
    sprite_t dead;
    fb_t fb;
    dg_scene_t *layer;
} data_t;

void gun_shot(data_t *data, sfTime dt);
void ball_shot(data_t *data, sfTime dt);
void dead_shot(data_t *data, sfTime dt);

#endif /*INTRO_H_*/
