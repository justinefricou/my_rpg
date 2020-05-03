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
#include "intro.h"

static const sfColor blood = {140, 0, 0, 255};

void gun_shot(data_t *data, sfTime dt)
{
    if (data->clock > 0.5 && data->clock < 1) {
        *(data->gun.rot) -= sfTime_asMilliseconds(dt) / 10.0;
        data->gun.pos->x -= sfTime_asMilliseconds(dt);
        data->gun.pos->y += sfTime_asMilliseconds(dt) * 1.4;
    } else if (data->clock < 1.1) {
        *(data->gun.rot) += sfTime_asMilliseconds(dt);
        data->gun.pos->x += sfTime_asMilliseconds(dt) * 10;
        data->gun.pos->y -= sfTime_asMilliseconds(dt) * 10;
        dg_fb_putcircle(data->fb.fb, (sfVector2u){1350, 300}, 40, sfWhite);
    } else {
        dg_fb_putcircle(data->fb.fb, (sfVector2u){1350 - (data->clock - 1.1)
            * 1600, 300}, 40, sfWhite);
    }
}

void ball_shot(data_t *data, sfTime dt)
{
    if (data->clock < 2) {
        dg_fb_putcircle(data->fb.fb, (sfVector2u){650, 300}, 40, sfWhite);
        data->gun.pos->x += sfTime_asMilliseconds(dt) * 2;
    } else if (data->clock < 4.2) {
        dg_fb_putcircle(data->fb.fb, (sfVector2u){
            650 + (data->clock - 2) * 150,
            300 + (data->clock - 2) * 60},
            40 + (data->clock - 2) * 30, sfWhite);
    } else {
        dg_fb_putcircle(data->fb.fb, (sfVector2u){980, 430}, 106, sfWhite);
    }
}

void dead_shot(data_t *data, sfTime dt)
{
    if (data->clock < 6.1) {
        data->dead.pos->x = -700;
        data->dead.pos->y = -1900;
        data->dead.size->x = 300;
        data->dead.size->y = 300;
    }
    if (data->clock < 7) {
        dg_fb_fill(data->fb.fb, blood);
        data->dead.pos->x += sfTime_asMilliseconds(dt) * 1.2;
        data->dead.pos->y += sfTime_asMilliseconds(dt) * 1.7;
        data->dead.size->x -= sfTime_asMilliseconds(dt) / 4;
        data->dead.size->y -= sfTime_asMilliseconds(dt) / 4;
        dg_fb_putcircle(data->fb.fb, (sfVector2u){980, 430},
        106 + (data->clock - 5) * 40, blood);
    } else if (data->clock < 8) {
        data->dead.pos->y += sfTime_asMilliseconds(dt) * 2;
        data->dead.size->y -= sfTime_asMilliseconds(dt) / 10.0;
        dg_fb_fill(data->fb.fb, blood);
    } else {
    }
}