/*
** EPITECH PROJECT, 2020
** cpt_scale
** File description:
** cpt_scale
*/

#include <stdlib.h>
#include "libdragon.h"
#include "particle.h"

static sfVector2i add_random_particule_round(sfVector2i fb_size,
    sfVector2i particle_size)
{
    sfVector2i pos = {0};
    sfVector2i radius = {fb_size.x / 2 - particle_size.x,
        fb_size.y / 2 - particle_size.y};
    int angle_degree = rand() % 360 - 180;
    float angle = angle_degree / 180.0 * PI; 

    pos.x = dg_cos(angle) * (rand() % radius.x) + fb_size.y / 2;
    pos.y = dg_sin(angle) * (rand() % radius.y) + fb_size.y / 2; 
    return pos;
}

static sfVector2i add_random_particule_square(sfVector2i fb_size,
    sfVector2i particle_size)
{
    sfVector2i pos = {0};
    sfVector2i x_bound = {particle_size.x, fb_size.x - particle_size.x};
    sfVector2i y_bound = {particle_size.y, fb_size.y - particle_size.y};

    pos.x = x_bound.x + rand() % (x_bound.y - x_bound.x);
    pos.y = y_bound.x + rand() % (y_bound.y - y_bound.x);
    return pos;
}

sfVector2i add_random_particule(int limit_type,
    sfVector2i fb_size, sfVector2i particle_size)
{
    if (limit_type == ROUND) {
        return add_random_particule_round(fb_size, particle_size);
    } else {
        return add_random_particule_square(fb_size, particle_size);
    }
}