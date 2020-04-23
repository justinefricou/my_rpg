/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** game_scenes
*/

#ifndef GAME_SCENES_H_
#define GAME_SCENES_H_

#include "libdragon.h"

#define NB_FIGHT_SCENE 6

void get_fight_scenes(dg_scene_t **scenes, int escape);
void create_fight_scenes(dg_window_t *w, int id);
void remove_fight_scenes(void);

#endif /*GAME_SCENES_H_*/
