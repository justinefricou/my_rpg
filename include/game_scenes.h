/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** game_scenes
*/

#ifndef GAME_SCENES_H_
#define GAME_SCENES_H_

#include "libdragon.h"

#define NB_GAME_SCENE 7

void get_game_scenes(dg_scene_t **scenes, int escape);
void create_game_scenes(dg_window_t *w);
void remove_game_scenes(void);

//buttons
void main_menu(int *previous, void *data, dg_window_t *w);
void status(int *previous, void *data, dg_window_t *w);
void inventory(int *previous, void *data, dg_window_t *w);
void clues(int *previous, void *data, dg_window_t *w);
void save(int *previous, void *data, dg_window_t *w);

#endif /*GAME_SCENES_H_*/
