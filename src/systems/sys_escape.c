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

void sys_escape(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    general_data_t *gd = w->general_data;
    dg_scene_t *game_scenes[NB_GAME_SCENE] = {0};

    if (gd->lock.menu)
        return;
    get_game_scenes(game_scenes, 1);
    if (keymap_is_clicked(w, "cancel", 1)) {
        for (int i = 0; i < NB_GAME_SCENE - 1; i++)
            game_scenes[i]->run = 0;
        scn_change(game_scenes[NB_GAME_SCENE - 1], 1);
    }
}