/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** game scenes utils
*/

#include "libdragon.h"
#include "game_scenes.h"
#include "ecs.h"

void get_game_scenes(dg_scene_t **scenes, int escape)
{
    scenes[0] = dg_scene_manager_get_scene("layer_event");
    scenes[1] = dg_scene_manager_get_scene("layer_top");
    scenes[2] = dg_scene_manager_get_scene("layer_middle");
    scenes[3] = dg_scene_manager_get_scene("layer_bottom");
    scenes[4] = dg_scene_manager_get_scene("layer_hud");
    if (escape)
        scenes[5] = dg_scene_manager_get_scene("escape_menu");
}

void create_game_scenes(void)
{
    dg_scene_manager_add_scene(scene_game_bottom());
    dg_scene_manager_add_scene(scene_game_middle());
    dg_scene_manager_add_scene(scene_game_event());
    dg_scene_manager_add_scene(scene_game_top());
    dg_scene_manager_add_scene(scene_game_hud());
    dg_scene_manager_add_scene(scene_escape_menu());
}

void remove_game_scenes(void)
{
    dg_scene_t *game_scenes[NB_GAME_SCENE] = {0};

    get_game_scenes(game_scenes, 0);
    for (int i = 0; i < NB_GAME_SCENE; i++) {
        dg_scene_manager_remove(game_scenes[i]->name);
    }
}