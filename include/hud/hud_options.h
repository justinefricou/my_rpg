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

typedef struct op_slot {
    dg_entity_t *data;
    dg_entity_t *name;
} op_slot_t;

typedef struct content {
    op_slot_t volume_general;
    op_slot_t volume_music;
    op_slot_t volume_sound;
    op_slot_t keymap_up;
    op_slot_t keymap_down;
    op_slot_t keymap_left;
    op_slot_t keymap_right;
    op_slot_t keymap_action;
    op_slot_t keymap_cancel;
    op_slot_t language;
    op_slot_t main;
} content_t;

typedef struct selector {
    dg_entity_t *entity;
    sfVector2f *pos;
} selector_t;

typedef struct data {
    dg_scene_t *hover_layer;
    float gvm;
    int *previous;
    content_t content;
    selector_t selector;
    sfVector2i mouse_memory;
    int select;
    int is_active;
    sfMusic *sound_move;
    sfMusic *sound_activate;
} data_t;

void options_set_data(data_t *data, dg_scene_t *scene,
    dg_entity_t *ent, general_data_t *gd);
void act_by_selected(data_t *data);
void update_sound(data_t *data, general_data_t *gd);
void options_set_main(data_t *data, general_data_t *gd);
void options_set_escape(data_t *data, general_data_t *gd);
float update_selector(data_t *data);
void reset_selected(data_t *data);

#endif /*HUD_OPTIONS_H_*/