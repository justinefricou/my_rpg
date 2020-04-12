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

static void go_to_game(dg_window_t *w)
{
    create_game_scenes();
    dg_scene_manager_remove("main_menu");
}

static void go_to_how(dg_window_t *w)
{
    dg_scene_manager_add_scene(scene_how_to_play());
    dg_scene_manager_remove("main_menu");
}

static void go_to_quit(dg_window_t *w)
{
    w->quit = 1;
}

dg_scene_t *scene_main_menu(void)
{
    dg_scene_t *scene = dg_scene_create("main_menu");
    button_t button_list[6] = {(button_t){"New game", &go_to_game},
        (button_t){"Load Game", &go_to_game},
        (button_t){"How to play", &go_to_how},
        (button_t){"Options", &go_to_how},
        (button_t){"Quit", &go_to_quit},
        (button_t){NULL, NULL}};

    dg_scene_add_ent(scene, ent_hud_menu_selector((sfVector2f){300, 700},
        button_list, scene, 1));
    dg_scene_add_ent(scene, ent_music("./sound/menu_song.ogg"));
    dg_scene_add_ent(scene, ent_sprite(0, 1, 0, 0));
    dg_scene_add_ent(scene, ent_text(300, 100, 200, "RPG"));
    dg_scene_add_ent(scene, ent_text(1200, 150, 150, "Menu"));
    dg_scene_add_ent(scene, dg_ent_camera(0, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_display_text, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_shape_rectangle, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_tm_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_script, 0));
    scene->run = 1;
    scene->display = 1;
    return scene;
}