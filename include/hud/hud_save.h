/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** hud save
*/

#ifndef HUD_SAVE_H_
#define HUD_SAVE_H_

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

void save_set_sounds(data_t *data);
void save_set_data(data_t *data, dg_scene_t *scene);
void save_update_position(data_t *data);

#endif /*HUD_SAVE_H_*/
