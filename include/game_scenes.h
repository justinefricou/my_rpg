/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** game_scenes
*/

#ifndef GAME_SCENES_H_
#define GAME_SCENES_H_

#include "libdragon.h"

#define NB_GAME_SCENE 6

void get_game_scenes(dg_scene_t **scenes, int escape);
void create_game_scenes(void);
void remove_game_scenes(void);

#endif /*GAME_SCENES_H_*/
