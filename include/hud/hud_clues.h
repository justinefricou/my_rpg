/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** epitech forbidden functions
*/

#ifndef HUD_CLUES_H_
#define HUD_CLUES_H_

#include "libdragon.h"
#include "ecs.h"
#include "hud.h"

//!\Do NOT INCLUDE SOMEWHERE ELSE THAN IN INVENTORY FILES

typedef struct data {
    int *previous;
    sfVector2f *pos;
    dg_entity_t *hud_box;
    dg_scene_t *layer;
    int select;
    sfText *text[20];
    sfMusic *sound_move;
    sfMusic *sound_activate;
} data_t;

void clues_set_sounds(data_t *data);
void clues_set_data(data_t *data);
void clues_update(data_t *data, dg_window_t *w);

#endif /*HUD_INVENTORY_H_*/
