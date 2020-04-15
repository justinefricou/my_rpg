/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** hud save
*/

#ifndef HUD_HTP_H_
#define HUD_HTP_H_

#include "libdragon.h"
#include "ecs.h"
#include "hud.h"

//!\Do NOT INCLUDE SOMEWHERE ELSE THAN IN INVENTORY FILES

typedef struct data {
    int *previous;
    sfVector2f *pos;
    dg_entity_t *hud_box;
    sfRectangleShape *selector;
    int select;
    int is_active;
    sfMusic *sound_move;
    sfMusic *sound_activate;
} data_t;

void htp_set_sounds(data_t *data);

#endif /*HUD_HTP_H_*/
