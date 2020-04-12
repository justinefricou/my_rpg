/*
** EPITECH PROJECT, 2020
** scene_escape_menu
** File description:
** scene_escape_menu
*/

#include <stdlib.h>
#include "libdragon.h"
#include "game_scenes.h"
#include "ecs.h"
#include "hud.h"

static void go_to_resume(dg_window_t *w)
{
    dg_scene_t *escape_menu = dg_scene_manager_get_scene("escape_menu");
    dg_scene_t *game_scenes[NB_GAME_SCENE - 1] = {0};

    get_game_scenes(game_scenes, 0);
    scn_change(escape_menu, 0);
    for (int i = 0; i < NB_GAME_SCENE - 1; i++) {
        scn_change(game_scenes[i], 1);
    }
}

static void go_to_menu(dg_window_t *w)
{
    dg_scene_manager_add_scene(scene_main_menu());
    remove_game_scenes();
}

static void go_to_quit(dg_window_t *w)
{
    w->quit = 1;
}

dg_scene_t *scene_escape_menu(void)
{
    dg_scene_t *scene = dg_scene_create("escape_menu");
    button_t button_list[6] = {(button_t){"Resume", &go_to_resume},
        (button_t){"Inventory", &go_to_quit}, (button_t){"Save", &go_to_quit},
        (button_t){"Menu", &go_to_menu}, (button_t){"Quit", &go_to_quit},
        (button_t){NULL, NULL}};

    dg_scene_add_ent(scene, ent_hud_menu_selector((sfVector2f){20, 20},
        button_list, scene, 1));
    dg_scene_add_ent(scene, dg_ent_camera(0, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_display_text, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_shape_rectangle, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_tm_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_button, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_script, 0));
    scene->run = 0;
    scene->display = 0;
    return scene;
}