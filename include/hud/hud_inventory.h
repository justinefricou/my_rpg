/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** epitech forbidden functions
*/

#ifndef HUD_INVENTORY_H_
#define HUD_INVENTORY_H_

#include "libdragon.h"
#include "ecs.h"
#include "hud.h"

//!\Do NOT INCLUDE SOMEWHERE ELSE THAN IN INVENTORY FILES

typedef struct selector {
    sfRectangleShape *selector;
    int select;
    int defilement;
} selector_t;

typedef struct data {
    int *previous;
    sfVector2f *pos;
    dg_entity_t *hud_box;
    selector_t selector;
    int is_active;
    sfMusic *sound_move;
    sfMusic *sound_activate;
} data_t;

void inventory_set_data(data_t *data, dg_entity_t *entity);
void inventory_update_selector(data_t *data, general_data_t *dt);
void inventory_manage_move(dg_window_t *w, data_t *data);

#endif /*HUD_INVENTORY_H_*/
