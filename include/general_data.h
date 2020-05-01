/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** epitech forbidden functions
*/

#include "object.h"
#include "libdragon.h"
#include "event.h"
#include "map.h"
#include "init_dialogs.h"

#ifndef GENERAL_DATA_H_
#define GENERAL_DATA_H_

#define OBJECT_LIST 1
#define CLUES_LEN 1
#define SPRITE_ID_LEN 1

typedef dg_animator_t *(*set_animator_t)(void);

typedef struct inventory_slot
{
    int nb;
    int id;
} inventory_slot_t;

typedef struct inventory
{
    int len;
    sfVector2f stack;
    inventory_slot_t slot[100];
} inventory_t;

typedef struct player
{
    char *name;
    sfVector2f pv;
    sfVector2f pm;
    int level;
    sfVector2f xp;
    int money;
    float damage;
} player_t;

typedef struct clues
{
    int len;
    int list[CLUES_LEN];
} clues_t;

typedef enum skill_type
{
    FLATTERY = 0,
    INTIMIDATION = 1,
    REPARTEE = 2,
    TRICKERY = 3,
} skill_type;

typedef struct skill
{
    char *name;
    char *description;
    skill_type type;
} skill_t;

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

typedef struct map {
    int len;
    map_data_t *map;
} map_t;

typedef struct lock
{
    int move;
    int menu;
} lock_t;

typedef struct enemy
{
    sfVector2f pv;
    skill_type type;
} enemy_t;

typedef struct general_data
{
    inventory_t inventory;
    clues_t clues;
    skill_t *skills;
    player_t player;
    enemy_t enemy;
    object_list_t object_list;
    event_manager_t event_manager;
    map_t maps;
    dialogs_t dialogs;
    options_t options;
    int block_input;
    set_animator_t sprite_id[SPRITE_ID_LEN];
    lock_t lock;
} general_data_t;

general_data_t *create_general_data(void);
void free_general_data(general_data_t *gd);
void set_volume(dg_window_t *w);
map_t set_map_data(void);
void set_sprite_id(general_data_t *gd);
void create_events(general_data_t *gd);
void unlock_clue(general_data_t *gd, int id);

//key
int key_is_clicked(dg_window_t *w, sfKeyCode key, int force_ignore);
int key_is_pressed(dg_window_t *w, sfKeyCode key);
int keymap_is_pressed(dg_window_t *w, char *keymap);
int keymap_is_clicked(dg_window_t *w, char *keymap, int force_ignore);
sfKeyCode get_keymap(dg_window_t *w, char *keymap);
const char *keycode_to_text(sfKeyCode code);
int is_keymap(dg_window_t *w, sfKeyCode keymap);

//inventory
int add_to_inventory(general_data_t *gd, int id, int nb);
int remove_from_inventory(general_data_t *gd, int id, int nb);
int is_in_inventory(general_data_t *gd, int id, int nb);
int how_much_in_inventory(general_data_t *gd, int id);

//events
map_data_t get_map_data(char *name, general_data_t *gd);

//loop
void fix_empty_slot(general_data_t *gd, int hole);
void update_inventory(general_data_t *gd);
void update_level(general_data_t *gd);

#endif /*GENERAL_DATA_H_*/
