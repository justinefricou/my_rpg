/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** script structure
*/

#include "libdragon.h"

#ifndef SCRIPT_H_
#define SCRIPT_H_

typedef struct script
{
    void *(*init)(void *);
    dg_sysf_t loop;
    void (*end)(void *);
    void *data;
} script_t;

/*
// build menu
void *scp_build_menu_init(void *init_data);
void scp_build_menu_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void scp_build_menu_end(void *data);
*/

// player controller
void *scp_player_controller_init(void *init_data);
void scp_player_controller_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void scp_player_controller_end(void *data);

// hud_menu_selector
void *scp_hud_menu_selector_init(void *init_data);
void scp_hud_menu_selector_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void scp_hud_menu_selector_end(void *data);

#endif /*SCRIPT_H_*/
