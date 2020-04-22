/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** game scenes utils
*/

#include <stdlib.h>
#include "libdragon.h"
#include "fight_scenes.h"
#include "ecs.h"

static int **create_test_map(void)
{
    int **map = malloc(sizeof(int *) * 100);

    for (int i = 0; i < 100 - 1; i++) {
        map[i] = malloc(sizeof(int) * 100);
        for (int j = 0; j < 100 - 1; j++)
            map[i][j] = 6;
        map[i][99] = -1;
    }
    map[99] = NULL;
    return map;
}

void get_fight_scenes(dg_scene_t **scenes, int escape)
{
    scenes[0] = dg_scene_manager_get_scene("layer_event_fight");
    scenes[1] = dg_scene_manager_get_scene("layer_top_fight");
    scenes[2] = dg_scene_manager_get_scene("layer_middle_fight");
    scenes[3] = dg_scene_manager_get_scene("layer_bottom_fight");
    scenes[4] = dg_scene_manager_get_scene("layer_hud_fight");
}

void create_fight_scenes(dg_window_t *w)
{
    int **map = create_test_map();
    dg_scene_t *event = scene_fight_event(map);

    dg_scene_manager_add_scene(scene_fight_bottom(map, event));
    dg_scene_manager_add_scene(scene_fight_middle());
    dg_scene_manager_add_scene(scene_fight_top());
    dg_scene_manager_add_scene(scene_fight_hud(w));
}

void remove_fight_scenes(void)
{
    dg_scene_t *game_scenes[NB_FIGHT_SCENE] = {0};

    get_fight_scenes(game_scenes, 1);
    for (int i = 0; i < NB_FIGHT_SCENE; i++) {
        dg_scene_manager_remove(game_scenes[i]->name);
    }
}