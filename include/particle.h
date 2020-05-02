/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** particle
*/

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "libdragon.h"

#define PARTICLE_TYPE_LEN 2

enum {PARTICLE_NONE, SPARKLE, JET};

enum {ROUND, SQUARE};

typedef struct sparkle_context {
    sfVector2f position;
    sfVector2i dispersion;
    float density;
    int size;
    float duration;
    int dispersion_type;
    sfColor color;
} sparkle_context_t;

typedef struct particle_intern {
    sfVector2i pos;
    float clock;
} particle_intern_t;

typedef struct particle_sparkle {
    sfVector2i dispersion;
    float density;
    int size;
    int nb;
    float duration;
    int dispersion_type;
    particle_intern_t *particles;
} particle_sparkle_t;

typedef struct particle_system {
    dg_framebuffer_t *fb;
    int type;
    float clock;
    sfVector2f pos;
    void *data;
    sfColor color;
} particle_system_t;

typedef void (*particle_setter_t)(particle_system_t *ps);
typedef void (*particle_updater_t)(particle_system_t *ps, sfTime dt);

particle_system_t *particle_create(sfVector2f pos);
void particle_destroy(particle_system_t *ps);
void particle_set_type(particle_system_t *particle, int type);
void particle_reset(particle_system_t *particle);
void particle_calcul_update(particle_system_t *ps, sfTime dt);
sfVector2i add_random_particule(int limit_type,
    sfVector2i fb_size, sfVector2i particle_size);

//set type
void particle_set_none(particle_system_t *ps);
void particle_set_sparkle(particle_system_t *ps);

//update
void particle_calcul_update_sparkle(particle_system_t *ps, sfTime dt);

//sparkle change
void sparkle_change_density(particle_system_t *ps, float density);
void sparkle_change_dispersion(particle_system_t *ps, sfVector2i dispersion);
void sparkle_change_dispersion_type(particle_system_t *ps,
    int dispersion_type);
void sparkle_change_size(particle_system_t *ps, int size);
void sparkle_change_duration(particle_system_t *ps, float duration);
void sparkle_force_update(particle_system_t *ps);

#endif /*PARTICLE_H_*/
