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
#include "hud.h"

//!\Do NOT INCLUDE SOMEWHERE ELSE THAN IN MENU SELECTOR FILES

typedef struct data {
    button_t *button_list;
    button_t cancel;
    sfVector2f pos_memory;
    sfVector2f *pos;
    sfVector2i mouse_memory;
    dg_entity_t *hud_box;
    dg_entity_t **buttons;
    sfRectangleShape *selector;
    int llen;
    int select;
    int is_active;
    sfMusic *sound_move;
    sfMusic *sound_activate;
} data_t;

sfVector2f get_longest_name(data_t *data);
dg_entity_t **create_buttons(sfVector2f pos, dg_scene_t *scene,
    button_t *button_list, int len);
void update_position(data_t *data);
data_t *menu_selector_set_data(dg_component_t *pos,
    button_t *button_list, dg_scene_t *scene, int has_box);
sfVector2f menu_selector_set_rect(data_t *data);
void hud_menu_manage_mouse(dg_window_t *w, data_t *data);
void hud_options_manage_mouse(dg_window_t *w, data_t *data);

#endif /*HUD_MENU_SELECTOR_H_*/
