/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Saving and loading a game : header
*/

#ifndef DEF_SAVE_LOAD_H_
#define DEF_SAVE_LOAD_H_

#include <stdio.h>
#include "general_data.h"

// save_load_utils.c
int open_save_file(FILE **save_file, int save_nb, char *mode);
int write_int_in_save_file(int nbr, FILE *save_file);
int write_str_in_save_file(char *str, FILE *save_file);
char *get_line_from_save_file(FILE *save_file);
int get_nbr_until(char *str, char end);


/*                GAME                */

// save_game.c
int save_game(general_data_t *data, int save_nb);

// load_saved_game.c
int load_saved_game(general_data_t *data, int save_nb);

/*
** PLAYER
*/

// save_player_info.c
void save_player_name(char *name, FILE *save_file);
void save_player_position(sfVector2f *position, FILE *save_file);
void save_player_lvl_and_xp(player_t player, FILE *save_file);

// load_saved_player_info.c
int load_saved_player_name(general_data_t *data, FILE *save_file);
int load_saved_player_position(sfVector2f *position, FILE *save_file);
int load_saved_player_lvl(player_t *player, FILE *save_file);
int load_saved_player_xp(player_t *player, FILE *save_file);

// save_player_status.c
void save_player_pv(sfVector2f pv, FILE *save_file);
void save_player_pm(sfVector2f pm, FILE *save_file);
void save_player_money(player_t player, FILE *save_file);

// load_saved_player_status.c
int load_saved_player_pv(general_data_t *data, FILE *save_file);
int load_saved_player_pm(general_data_t *data, FILE *save_file);
int load_saved_player_money(player_t *player, FILE *save_file);

/*
** PROGRESSION
*/

// save_inventory.c
void save_inventory(inventory_t inventory, FILE *save_file);

// load_saved_inventory.c
int load_saved_inventory(inventory_t *inventory, FILE *save_file);

// save_clues.c
void save_clues(clues_t clues, FILE *save_file);

// load_saved_clues.c
int load_saved_clues(clues_t *clues, FILE *save_file);


/*               OPTIONS               */

// save_options.c
int save_options(options_t options);

// load_saved_options.c
int load_saved_options(options_t *options);

// save_options_volume.c
void save_general_volume(options_t options, FILE *save_file);
void save_music_volume(options_t options, FILE *save_file);
void save_sound_volume(options_t options, FILE *save_file);

// load_saved_options_volume.c
int load_saved_general_volume(options_t *options, FILE *save_file);
int load_saved_music_volume(options_t *options, FILE *save_file);
int load_saved_sound_volume(options_t *options, FILE *save_file);

// save_options_keymap.c
void save_keymap(keymap_t keymap, FILE *save_file);

// load_saved_options_keymap.c
int load_saved_keymap(keymap_t *keymap, FILE *save_file);

#endif /*DEF_SAVE_LOAD_H_*/