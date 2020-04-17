/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** epitech forbidden functions
*/

#ifndef GENERAL_DATA_H_
#define GENERAL_DATA_H_

#include "object.h"
#include "libdragon.h"

#define OBJECT_LIST 1

typedef struct inventory_slot
{
    int nb;
    object_t object;
} inventory_slot_t;

typedef struct inventory
{
    int len;
    int max_len;
    inventory_slot_t *slot;
} inventory_t;

typedef struct player
{
    char *name;
    int pv;
    int pm;
} player_t;

typedef struct clues
{
    int unused;
} clues_t;

typedef struct keymap
{
    sfKeyCode up;
    sfKeyCode left;
    sfKeyCode down;
    sfKeyCode right;
    sfKeyCode action;
    sfKeyCode cancel;
} keymap_t;

typedef struct options
{
    sfVector2f general_volume;
    sfVector2f music;
    sfVector2f sound;
    int resolution;
    keymap_t keymap;
} options_t;

typedef struct object_list {
    int len;
    object_t object[OBJECT_LIST];
} object_list_t;

typedef struct general_data
{
    inventory_t inventory;
    clues_t clues;
    player_t player;
    object_list_t object_list;
    options_t options;
    int block_input;
} general_data_t;

general_data_t *create_general_data(void);
void free_general_data(general_data_t *gd);
void set_volume(dg_window_t *w);

//key
int key_is_clicked(dg_window_t *w, sfKeyCode key, int force_ignore);
int key_is_pressed(dg_window_t *w, sfKeyCode key);
int keymap_is_pressed(dg_window_t *w, char *keymap);
int keymap_is_clicked(dg_window_t *w, char *keymap, int force_ignore);
sfKeyCode get_keymap(dg_window_t *w, char *keymap);
const char *keycode_to_text(sfKeyCode code);
int is_keymap(dg_window_t *w, sfKeyCode keymap);

#endif /*GENERAL_DATA_H_*/
