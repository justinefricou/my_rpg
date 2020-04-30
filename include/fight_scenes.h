/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** game_scenes
*/

#ifndef FIGHT_SCENES_H_
#define FIGHT_SCENES_H_

#include "libdragon.h"

#define NB_FIGHT_SCENE 5

void create_fight_scenes(dg_window_t *w, int id);
void remove_fight_scenes(void);

void fight_skill(int *previous, void *data, dg_window_t *w);

#endif /*FIGHT_SCENES_H_*/
