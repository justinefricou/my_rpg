/*
** EPITECH PROJECT, 2020
** sys_escape
** File description:
** sys_escape
*/

#include <stdlib.h>
#include "libdragon.h"
#include "game_scenes.h"
#include "general_data.h"
#include "ecs.h"

void sys_quit(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    general_data_t *gd = w->general_data;
    dg_scene_t *game_scenes[NB_GAME_SCENE] = {0};

    if (gd->auto_quit) {
         dg_scene_manager_add_scene(scene_main_menu());
        dg_scene_manager_add_scene(scene_main_menu_hover());
        sfMusic_play(dg_ressources_get_audio_by_name("menu_theme"));
        sfMusic_stop(dg_ressources_get_audio_by_name("game_theme"));
        remove_game_scenes();
        gd->auto_quit = 0;
    }
}