/*
** EPITECH PROJECT, 2020
** sys_escape
** File description:
** sys_escape
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

void sys_escape(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_scene_t *scene_escape = dg_scene_manager_get_scene("escape_menu");
    dg_scene_t *game_scene = dg_scene_manager_get_scene("game");
    dg_entity_t *music_ent = dg_get_entity(*entities, "music");
    sfMusic *music_music = dg_entity_get_component(music_ent, "sound");

    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        game_scene->run = 0;
        scene_escape->display = 1;
        scene_escape->run = 1;
        sfMusic_stop(music_music);
    }
}