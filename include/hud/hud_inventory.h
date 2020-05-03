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

#include "sprite.h"

#define NB_SLOT 24

typedef struct selector {
    sfRectangleShape *selector;
    int select;
    int defilement;
} selector_t;

typedef struct inv_icon {
    dg_entity_t *entity;
    sprite_t *id;
} inv_icon_t;

typedef struct inv_text {
    dg_entity_t *entity;
    sfText *text;
} inv_text_t;

typedef struct inv_slot {
    inv_icon_t icon;
    inv_text_t name;
    inv_text_t quantity;
} inv_slot_t;

typedef struct inv_hover {
    dg_scene_t *layer;
    inv_slot_t slots[NB_SLOT];
} inv_hover_t;

typedef struct inv_action {
    dg_scene_t *layer;
    sfText *description;
} inv_action_t;

typedef struct data {
    int *previous;
    sfVector2f *pos;
    dg_entity_t *hud_box;
    dg_entity_t *side_box;
    dg_entity_t *skill_box;
    dg_entity_t *fx;
    sfText *weight;
    selector_t selector;
    inv_hover_t slots;
    int is_active;
    int launch_action;
    dg_scene_t *inv_action;
    sfMusic *sound_move;
    sfMusic *sound_activate;
} data_t;

void inventory_set_data(data_t *data, dg_entity_t *entity);
void inventory_update_selector(data_t *data, general_data_t *dt);
void inventory_manage_move(dg_window_t *w, data_t *data);
void inventory_active_slot(data_t *data, int id, int status);
void inventory_update_slot(data_t *data, general_data_t *gd);
void inventory_update_weight(data_t *data, general_data_t *gd);
void inventory_action(data_t *data, general_data_t *gd);

//actions
void inv_use(int *previous, void *data, dg_window_t *w);
void inv_throw(int *previous, void *data, dg_window_t *w);
void inv_cancel(int *previous, void *data, dg_window_t *w);

#endif /*HUD_INVENTORY_H_*/
