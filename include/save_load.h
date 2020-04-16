/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Saving and loading a game : header
*/

#ifndef DEF_SAVE_LOAD_H_
#define DEF_SAVE_LOAD_H_

#include "general_data.h"

// save_load_utils.c
int open_save_file(FILE **save_file, int save_nb, char *mode);

// save_game.c
int save_game(general_data_t *data, int save_nb);
int save_data(general_data_t *data, FILE *save_file);

// save_player_info.c
void save_player_name(char *name, FILE *save_file);
void save_player_pv(int pv, FILE *save_file);

// load_game.c
int load_saved_game(general_data_t *data, int save_nb);
int load_saved_data(general_data_t *data, FILE *save_file);

// load_player_info.c
int load_saved_player_name(general_data_t *data, FILE *save_file);
int load_saved_player_pv(general_data_t *data, FILE *save_file);

#endif /*DEF_SAVE_LOAD_H_*/