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

static void initialise_stats(general_data_t *gd, int id)
{
    gd->enemy.pv.x = 100;
    gd->enemy.pv.y = 100;
    gd->enemy.type = 1;
    gd->enemy.damage = 4 + (id * 2);
    gd->player.turn = 0;
    gd->player.defence = 1;
    gd->player.flattery_stat = 1;
    gd->player.intimidation_stat = 1;
    gd->player.repartee_stat = 1;
    gd->player.trickery_stat = 1;
}

void create_fight_scenes(dg_window_t *w, int id)
{
    int **map = create_test_map();
    dg_scene_t *event = scene_fight_event(map);
    general_data_t *gd = w->general_data;

    initialise_stats(gd, id);
    dg_scene_manager_add_scene(scene_fight_bottom(map, event));
    dg_scene_manager_add_scene(scene_fight_middle(id));
    dg_scene_manager_add_scene(scene_fight_top());
    dg_scene_manager_add_scene(scene_fight_hud(w, gd));
}

void remove_fight_scenes(void)
{
    dg_scene_manager_remove("layer_event_fight");
    dg_scene_manager_remove("layer_top_fight");
    dg_scene_manager_remove("layer_middle_fight");
    dg_scene_manager_remove("layer_bottom_fight");
    dg_scene_manager_remove("layer_hud_fight");
}