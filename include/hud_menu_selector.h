/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** epitech forbidden functions
*/

#ifndef HUD_MENU_SELECTOR_H_
#define HUD_MENU_SELECTOR_H_

#include "libdragon.h"
#include "ecs.h"

typedef void (*button_action_t)(dg_window_t *w);

typedef struct data {
    button_action_t *action;
    sfVector2f pos_memory;
    sfVector2f *pos;
    dg_entity_t *hud_box;
    dg_entity_t **buttons;
    sfRectangleShape *selector;
    int llen;
    int select;
    int is_active;
} data_t;

int get_longest_name(button_t *button_list, int len);
dg_entity_t **create_buttons(sfVector2f pos, dg_scene_t *scene,
    button_t *button_list, int len);
void update_position(data_t *data);
button_action_t *create_actions(button_t *button_list, int len);

#endif /*HUD_MENU_SELECTOR_H_*/
