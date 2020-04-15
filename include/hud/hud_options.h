/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** hud options
*/

#ifndef HUD_OPTIONS_H_
#define HUD_OPTIONS_H_

#include "libdragon.h"
#include "ecs.h"
#include "hud.h"

//!\Do NOT INCLUDE SOMEWHERE ELSE THAN IN INVENTORY FILES

typedef struct data {
    float gvm;
    int *previous;
    sfVector2f *pos;
    dg_entity_t *hud_box;
    dg_entity_t *general_volume;
    sfRectangleShape *selector;
    int select;
    int is_active;
    sfMusic *sound_move;
    sfMusic *sound_activate;
} data_t;

void options_set_sounds(data_t *data);
void options_set_data(data_t *data, dg_scene_t *scene, dg_entity_t *ent);

#endif /*HUD_OPTIONS_H_*/