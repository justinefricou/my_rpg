/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** game_scenes
*/

#ifndef SCRIPT_EVENT_H_
#define SCRIPT_EVENT_H_

 #include "instructions.h"

typedef struct reader {
    int active;
    int activation;
    int end;
    int progress;
    int len;
} reader_t;

typedef struct dialog {
    dg_entity_t *box;
    dg_entity_t *ent_text;
    sfText *text;
    dg_entity_t *hud_box;
} dialog_t;

typedef struct intern_data {
    struct intern_data *intern;
    reader_t reader;
    instruction_t *script;
    dialog_t dialog;
} intern_t;

typedef struct self_data {
    sfVector2f memory;
    sfVector2f *pos;
    dg_component_t *animator;
} self_data_t;

typedef struct data {
    intern_t intern;
    self_data_t self;
} data_t;

typedef intern_t *(*key_ini_t)(intern_t *prev);
typedef int (*key_act_t)(intern_t *, self_data_t,
    dg_window_t *);
typedef void (*key_end_t)(intern_t *);

//================functions key================================

//set
intern_t *ins_ini_set(intern_t *prev);
int ins_act_set(intern_t *intern, self_data_t data, dg_window_t *w);
void ins_end_set(intern_t *intern);

//if
intern_t *ins_ini_if(intern_t *prev);
int ins_act_if(intern_t *intern, self_data_t data, dg_window_t *w);
void ins_end_if(intern_t *intern);

//while
intern_t *ins_ini_while(intern_t *prev);
int ins_act_while(intern_t *intern, self_data_t data, dg_window_t *w);
void ins_end_while(intern_t *intern);

//for
intern_t *ins_ini_for(intern_t *prev);
int ins_act_for(intern_t *intern, self_data_t data, dg_window_t *w);
void ins_end_for(intern_t *intern);

//end
intern_t *ins_ini_end(intern_t *prev);
int ins_act_end(intern_t *intern, self_data_t data, dg_window_t *w);
void ins_end_end(intern_t *intern);

//give
intern_t *ins_ini_give(intern_t *prev);
int ins_act_give(intern_t *intern, self_data_t data, dg_window_t *w);
void ins_end_give(intern_t *intern);

//take
intern_t *ins_ini_take(intern_t *prev);
int ins_act_take(intern_t *intern, self_data_t data, dg_window_t *w);
void ins_end_take(intern_t *intern);

//tp
intern_t *ins_ini_tp(intern_t *prev);
int ins_act_tp(intern_t *intern, self_data_t data, dg_window_t *w);
void ins_end_tp(intern_t *intern);

//dialog
intern_t *ins_ini_dialog(intern_t *prev);
int ins_act_dialog(intern_t *intern, self_data_t data, dg_window_t *w);
void ins_end_dialog(intern_t *intern);

//talk
intern_t *ins_ini_talk(intern_t *prev);
int ins_act_talk(intern_t *intern, self_data_t data, dg_window_t *w);
void ins_end_talk(intern_t *intern);

//answer
intern_t *ins_ini_answer(intern_t *prev);
int ins_act_answer(intern_t *intern, self_data_t data, dg_window_t *w);
void ins_end_answer(intern_t *intern);

//battle
intern_t *ins_ini_battle(intern_t *prev);
int ins_act_battle(intern_t *intern, self_data_t data, dg_window_t *w);
void ins_end_battle(intern_t *intern);

//move
intern_t *ins_ini_move(intern_t *prev);
int ins_act_move(intern_t *intern, self_data_t data, dg_window_t *w);
void ins_end_move(intern_t *intern);

//==============================================================

extern const key_ini_t key_init[14];
extern const key_act_t key_active[14];
extern const key_end_t key_end[14];

//functions
void get_event_from_name(char *name, general_data_t *gd, data_t *data);
void event_active(intern_t *data, self_data_t self, dg_window_t *w);
void event_launch(intern_t *data);
void check_interaction(data_t *data, dg_array_t **entities, dg_window_t *w);

#endif /*SCRIPT_EVENT_H_*/
