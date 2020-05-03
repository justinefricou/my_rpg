/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** status hud
*/

#ifndef HUD_STATUS_H_
#define HUD_STATUS_H_

#include "libdragon.h"
#include "ecs.h"
#include "hud.h"

//!\Do NOT INCLUDE SOMEWHERE ELSE THAN IN STATUS FILES

typedef struct data {
    int *previous;
    dg_scene_t *layer;
    dg_entity_t *hud_box;
    sfMusic *sound_activate;
} data_t;

void status_set_sounds(data_t *data);
void status_set_data(data_t *data, dg_window_t *w);

void status_data_add(data_t *data);

#endif /*HUD_STATUS_H_*/
