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
    create_game_scenes();
    sfMusic_stop(dg_ressources_get_audio_by_name("menu_theme"));
    dg_scene_manager_remove("main_menu");
}

void load_game(int *previous, void *data, dg_window_t *w)
{
    sfMusic_stop(dg_ressources_get_audio_by_name("menu_theme"));
}

void how_to_play(int *previous, void *data, dg_window_t *w)
{
    dg_scene_manager_add_scene(scene_how_to_play());
    dg_scene_manager_remove("main_menu");

}

void options(int *previous, void *data, dg_window_t *w)
{

}