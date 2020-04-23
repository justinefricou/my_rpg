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
    scenes[3] = dg_scene_manager_get_scene("layer_bh");
    scenes[4] = dg_scene_manager_get_scene("layer_bottom");
    scenes[5] = dg_scene_manager_get_scene("layer_hud");
    if (escape)
        scenes[6] = dg_scene_manager_get_scene("escape_menu");
}

void create_game_scenes(general_data_t *gd, char *map_name)
{
    map_data_t map = get_map_data(map_name, gd);
    dg_scene_t *event = scene_game_event(map, gd);

    dg_scene_manager_add_scene(scene_game_bottom
        (map.layers.bottom, event));
    dg_scene_manager_add_scene(scene_game_bh
        (map.layers.bottom_hover, event));
    dg_scene_manager_add_scene(event);
    dg_scene_manager_add_scene(scene_game_middle
        (map.layers.middle, event));
    dg_scene_manager_add_scene(scene_game_top
        (map.layers.hover, event));
    dg_scene_manager_add_scene(scene_game_hud(gd));
    dg_scene_manager_add_scene(scene_escape_menu());
}

void remove_game_scenes(void)
{
    dg_scene_t *game_scenes[NB_GAME_SCENE] = {0};

    get_game_scenes(game_scenes, 1);
    for (int i = 0; i < NB_GAME_SCENE; i++) {
        dg_scene_manager_remove(game_scenes[i]->name);
    }
}