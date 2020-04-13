/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** button action
*/

#ifndef BUTTON_ACTION_H_
#define BUTTON_ACTION_H_

#include "libdragon.h"

void action_quit(int *previous, void *data, dg_window_t *w);

//scene menu
void new_game(int *previous, void *data, dg_window_t *w);
void load_game(int *previous, void *data, dg_window_t *w);
void how_to_play(int *previous, void *data, dg_window_t *w);
void options(int *previous, void *data, dg_window_t *w);

#endif /*BUTTON_ACTION_H_*/