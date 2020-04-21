/*
** EPITECH PROJECT, 2020
** scene_menu
** File description:
** scene_menu
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "game_scenes.h"
#include "button_action.h"

void new_game(int *previous, void *data, dg_window_t *w)
{
    create_fight_scenes();
    //w->general_data
    //create_game_scenes();
    sfMusic_stop(dg_ressources_get_audio_by_name("menu_theme"));
    sfMusic_play(dg_ressources_get_audio_by_name("game_theme"));
    dg_scene_manager_remove("main_menu");
}

void load_game(int *previous, void *data, dg_window_t *w)
{
    dg_scene_t *scene = dg_scene_manager_get_scene("main_menu_hover");

    *previous = 0;
    dg_scene_add_ent(scene, ent_hud_load(previous, scene));
}

void how_to_play(int *previous, void *data, dg_window_t *w)
{
    dg_scene_t *scene = dg_scene_manager_get_scene("main_menu_hover");

    *previous = 0;
    dg_scene_add_ent(scene, ent_hud_htp(previous, scene));
}