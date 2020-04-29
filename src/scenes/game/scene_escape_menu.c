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
#include "hud/hud.h"
#include "button_action.h"

static void resume(int *previous, void *data, dg_window_t *w)
{
    dg_scene_t *escape_menu = dg_scene_manager_get_scene("escape_menu");
    dg_scene_t *game_scenes[NB_GAME_SCENE - 1] = {0};

    get_game_scenes(game_scenes, 0);
    scn_change(escape_menu, 0);
    for (int i = 0; i < NB_GAME_SCENE - 1; i++) {
        scn_change(game_scenes[i], 1);
    }
}

static button_t *create_select_box(void)
{
    button_t *button_list = malloc(sizeof(button_t) * 9);

    button_list[0] = (button_t){"Resume", &resume, NULL};
    button_list[1] = (button_t){"Status", &status, NULL};
    button_list[2] = (button_t){"Inventory", &inventory, NULL};
    button_list[3] = (button_t){"Clues", &clues, NULL};
    button_list[4] = (button_t){"Save", &save, NULL};
    button_list[5] = (button_t){"Options", &action_options, "escape_menu"};
    button_list[6] = (button_t){"Menu", &main_menu, NULL};
    button_list[7] = (button_t){"Quit", &action_quit, NULL};
    button_list[8] = (button_t){NULL, NULL, NULL};
    return button_list;
}

dg_scene_t *scene_escape_menu(void)
{
    dg_scene_t *scene = dg_scene_create("escape_menu");
    button_t *button_list = create_select_box();

    dg_scene_add_ent(scene, ent_hud_cancel_menu_selector((sfVector2f){20, 20},
        button_list, scene, button_list[0]));
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