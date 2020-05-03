/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** scene bottom layer
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "button_action.h"
#include "fight_scenes.h"
#include "game_scenes.h"

static void fight_inventory(int *previous, void *data, dg_window_t *w)
{
    dg_scene_t *scene = dg_scene_manager_get_scene("layer_hud_fight");

    *previous = 0;
    dg_scene_add_ent(scene, ent_hud_fight_inventory(previous, scene));
}

static void quit_fight(int *previous, void *data, dg_window_t *w)
{
    general_data_t *gd = w->general_data;
    dg_scene_t *game_scenes[NB_GAME_SCENE];

    gd->event_manager.var[variable_to_int("BATTLE", gd)].data = 0;
    get_game_scenes(&game_scenes, 1);
    for (int i = 0; i < NB_GAME_SCENE; i++) {
        game_scenes[i]->display = 1;
        game_scenes[i]->run = 1;
    }
    sfMusic_play(dg_ressources_get_audio_by_name("game_theme"));
    sfMusic_stop(dg_ressources_get_audio_by_name("fight_theme"));
    remove_fight_scenes();
}

static button_t *create_select_box(void)
{
    button_t *button_list = malloc(sizeof(button_t) * 4);

    button_list[0] = (button_t){"Attack", &fight_skill, NULL};
    button_list[1] = (button_t){"Item", &fight_inventory, NULL};
    button_list[2] = (button_t){"Flee", &quit_fight, NULL};
    button_list[3] = (button_t){NULL, NULL, NULL};
    return button_list;
}

static void sys_hud(dg_scene_t *scene)
{
    dg_scene_add_sys(scene, dg_system_create(&sys_particle, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_shape_rectangle, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_display_text, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_sprite, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_tm_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_button, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_script, 0));
}

dg_scene_t *scene_fight_hud(dg_window_t *w, general_data_t *gd)
{
    dg_scene_t *scene = dg_scene_create("layer_hud_fight");
    sfVector2f *size = 0;
    dg_entity_t *ent = ent_hud_progress_bar(
        (sfVector2f){1520, 20}, 8, &(gd->player.xp), sfGreen);
    button_t *button_list = create_select_box();

    size = dg_entity_get_component(ent, "scale");
    size->y = 1;
    dg_scene_add_ent(scene, dg_ent_camera(0, 0));
    dg_scene_add_ent(scene, ent_hud_progress_bar(
        (sfVector2f){20, 20}, 5, &(gd->player.pv), sfRed));
    dg_scene_add_ent(scene, ent_hud_progress_bar(
        (sfVector2f){20, 70}, 5, &(gd->player.pm), sfBlue));
    dg_scene_add_ent(scene, ent_hud_progress_bar(
        (sfVector2f){1000, 20}, 5, &(gd->enemy.pv), sfRed));
    dg_scene_add_ent(scene, ent);
    dg_scene_add_ent(scene, ent_hud_menu_selector((sfVector2f){80, 600},
        button_list, scene, 1));
    sys_hud(scene);
    return scene;
}