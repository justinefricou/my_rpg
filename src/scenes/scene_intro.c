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
#include "particle.h"

dg_scene_t *scene_intro(void)
{
    dg_scene_t *scene = dg_scene_create("intro");
    sfMusic *music = dg_ressources_get_audio_by_name("menu_theme");

    dg_scene_add_ent(scene, dg_ent_camera(0, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_display_text, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_shape_rectangle, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_tm_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_particle, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_sprite, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_script, 0));
    if (sfMusic_getStatus(music) != sfPlaying) {
        sfMusic_setLoop(music, true);
        sfMusic_play(music);
    }
    return scene;
}