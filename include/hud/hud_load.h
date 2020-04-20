/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** hud load
*/

#ifndef HUD_LOAD_H_
#define HUD_LOAD_H_

#include "libdragon.h"
#include "ecs.h"
#include "hud.h"

//!\Do NOT INCLUDE SOMEWHERE ELSE THAN IN INVENTORY FILES

typedef struct data {
    int *previous;
    sfVector2f *pos;
    dg_entity_t *hud_box[4];
    dg_scene_t *layer;
    sfRectangleShape *selector;
    int select;
    int is_active;
    sfMusic *sound_move;
    sfMusic *sound_activate;
} data_t;

void load_set_sounds(data_t *data);
void load_set_data(data_t *data, dg_scene_t *scene);
void load_update_position(data_t *data);

#endif /*HUD_LOAD_H_*/
