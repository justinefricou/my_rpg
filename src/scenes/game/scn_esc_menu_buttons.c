/*
** EPITECH PROJECT, 2020
** scene_escape_menu
** File description:
** scene_escape_menu
*/

#include "libdragon.h"
#include "game_scenes.h"
#include "ecs.h"

void main_menu(int *previous, void *data, dg_window_t *w)
{
    dg_scene_manager_add_scene(scene_main_menu());
    remove_game_scenes();
}

void status(int *previous, void *data, dg_window_t *w)
{
    dg_scene_t *scene = dg_scene_manager_get_scene("escape_menu");

    *previous = 0;
    dg_scene_add_ent(scene, ent_hud_status(previous, scene));
}

void inventory(int *previous, void *data, dg_window_t *w)
{
    dg_scene_t *scene = dg_scene_manager_get_scene("escape_menu");

    *previous = 0;
    dg_scene_add_ent(scene, ent_hud_inventory(previous, scene));
}

void clues(int *previous, void *data, dg_window_t *w)
{
    dg_scene_t *scene = dg_scene_manager_get_scene("escape_menu");

    *previous = 0;
    dg_scene_add_ent(scene, ent_hud_clues(previous, scene));
}

void save(int *previous, void *data, dg_window_t *w)
{
    dg_scene_t *scene = dg_scene_manager_get_scene("escape_menu");

    *previous = 0;
    dg_scene_add_ent(scene, ent_hud_save(previous, scene));
}