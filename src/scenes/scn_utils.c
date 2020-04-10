/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** scenes utils
*/

#include "libdragon.h"
#include "ecs.h"

void scn_change_music(dg_scene_t *scene, int status)
{
    dg_entity_t *music_ent = dg_get_entity(scene->entities, "music");
    sfMusic *music = dg_entity_get_component(music_ent, "sound");

    switch(status) {
        case 0:
            sfMusic_stop(music);
            break;
        case 1:
            sfMusic_pause(music);
            break;
        case 2:
            sfMusic_play(music);
            break;
        case 3:
            sound_play(music);
            break;
    }
}

void scn_change(dg_scene_t *scene, int status)
{
    scene->display = status;
    scene->run = status;
}