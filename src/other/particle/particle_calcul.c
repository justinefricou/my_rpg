/*
** EPITECH PROJECT, 2020
** cpt_scale
** File description:
** cpt_scale
*/

#include <stdlib.h>
#include "libdragon.h"
#include "particle.h"

int check_color(sfColor a, sfColor b)
{
    int test = 0;
    test += a.r != b.r;
    test += a.g != b.g;
    test += a.b != b.b;
    test += a.a != b.a;
    return test;
}

void sparkle_force_update(particle_system_t *ps)
{
    particle_sparkle_t *intern = NULL;

    intern = ps->data;
    intern->nb = intern->density *
        (intern->dispersion.x * intern->dispersion.y);
    ps->fb = dg_framebuffer_create(intern->dispersion.x, intern->dispersion.y);
    intern->particles = malloc(sizeof(particle_intern_t) * intern->nb);
    for (int i = 0; i < intern->nb; i++) {
        do {
            intern->particles[i].pos =
                add_random_particule(intern->dispersion_type,
                (sfVector2i) {ps->fb->width, ps->fb->height},
                (sfVector2i) {intern->size, intern->size});
            intern->particles[i].clock =
                (float)(rand() % (int)(100 * intern->duration) / 100.0);
        } while (check_color(dg_fb_getpx(ps->fb, intern->particles[i].pos.x,
            intern->particles[i].pos.y), (sfColor) {0, 0, 0, 0}));
        dg_fb_putpx(ps->fb, intern->particles[i].pos.x,
            intern->particles[i].pos.y, ps->color);
    }
}

void rain_force_update(particle_system_t *ps)
{
    particle_rain_t *intern = NULL;

    intern = ps->data;
    intern->nb = intern->density *
        (intern->dispersion.x * intern->dispersion.y);
    ps->fb = dg_framebuffer_create(intern->dispersion.x, intern->dispersion.y);
    intern->particles = malloc(sizeof(particle_intern_t) * intern->nb);
    for (int i = 0; i < intern->nb; i++) {
        do {
            intern->particles[i].pos =
                add_random_particule(SQUARE,
                (sfVector2i) {ps->fb->width, ps->fb->height},
                (sfVector2i) {intern->size.x, intern->size.y});
            intern->particles[i].clock = (intern->speed / 2.0) +
                (rand() % (int)(intern->speed * 100) / 100);
        } while (check_color(dg_fb_getpx(ps->fb, intern->particles[i].pos.x,
            intern->particles[i].pos.y), (sfColor) {0, 0, 0, 0}));
        dg_fb_putpx(ps->fb, intern->particles[i].pos.x,
            intern->particles[i].pos.y, ps->color);
    }
}