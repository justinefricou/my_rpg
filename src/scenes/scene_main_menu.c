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

static button_t *create_select_box(void)
{
    button_t *button_list = malloc(sizeof(button_t) * 6);
    
    button_list[0] = (button_t){"New game", &new_game, NULL};
    button_list[1] = (button_t){"Load Game", &load_game, NULL};
    button_list[2] = (button_t){"How to play", &how_to_play, NULL};
    button_list[3] = (button_t){"Options", &options, NULL};
    button_list[4] = (button_t){"Quit", &action_quit, NULL};
    button_list[5] = (button_t){NULL, NULL, NULL};
    return button_list;
}

dg_scene_t *scene_main_menu(void)
{
    dg_scene_t *scene = dg_scene_create("main_menu");
    button_t *button_list = create_select_box();
    sfMusic *music = dg_ressources_get_audio_by_name("menu_theme");

    dg_scene_add_ent(scene, ent_hud_menu_selector((sfVector2f){300, 700},
        button_list, scene, 1));
    dg_scene_add_ent(scene, ent_sprite(0, 1, 0, 0));
    dg_scene_add_ent(scene, ent_text(300, 100, 200, "RPG"));
    dg_scene_add_ent(scene, ent_text(1200, 150, 150, "Menu"));
    dg_scene_add_ent(scene, dg_ent_camera(0, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_display_text, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_shape_rectangle, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_tm_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_script, 0));
    if (sfMusic_getStatus(music) != sfPlaying) {
        sfMusic_setLoop(music, true);
        sfMusic_play(music);
    }
    return scene;
}