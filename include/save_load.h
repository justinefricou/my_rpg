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
int write_int_in_save_file(int nbr, FILE *save_file);
int write_str_in_save_file(char *str, FILE *save_file);
char *get_line_from_save_file(FILE *save_file);
int get_nbr_until(char *str, char end);

/*          SAVE          */

// save_game.c
int save_game(general_data_t *data, int save_nb);

// save_player_info.c
void save_player_name(char *name, FILE *save_file);
void save_player_pv(int pv, FILE *save_file);
void save_player_position(sfVector2f *position, FILE *save_file);

// save_inventory.c
void save_inventory(inventory_t inventory, FILE *save_file);

/*          LOAD          */

// load_saved_game.c
int load_saved_game(general_data_t *data, int save_nb);

// load_saved_player_info.c
int load_saved_player_name(general_data_t *data, FILE *save_file);
int load_saved_player_pv(general_data_t *data, FILE *save_file);
int load_saved_player_position(sfVector2f *position, FILE *save_file);

// load_saved_inventory.c
int load_saved_inventory(inventory_t *inventory, FILE *save_file);

#endif /*DEF_SAVE_LOAD_H_*/