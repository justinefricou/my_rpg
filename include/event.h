/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** event function
*/

#ifndef EVENT_H_
#define EVENT_H_

#include "libdragon.h"

#define INSTRUCTIONS_NB 1

typedef struct parameters parameters_t;

typedef struct instruction {
    int keycode;
    parameters_t *parameters;
} instruction_t;

typedef union untyped_data {
    int n;
    char c;
    char *s;
    float f;
    instruction_t *i;
} untyped_data_t;

typedef struct parameters {
    int type;
    untyped_data_t parameters;
} parameters_t;

typedef struct variable {
    parameters_t data;
    char *name;
} variable_t;

typedef struct event {
    char *name;
    int sprite_id;
    instruction_t* parameters;
} event_t;

typedef struct event_manager {
    int var_len;
    variable_t *var;
    int event_len;
    event_t *events;
} event_manager_t;

enum {NONE, SET, IF, WHILE, FOR, END, GIVE, TAKE,
    TP, DIALOG, TALK, ANSWER, BATTLE, MOVE};

enum {INT, STRING, CHAR, FLOAT, INSTRUCTIONS,
    VARIABLE, CALCUL, EQUALITY, UNION};

enum {EQUAL, LESS, MORE, ELESS, EMORE, INEQUAL};
enum {PLUS, MINUS, DIVIDE, MULTIPLY};
enum {AND, OR, NON};

#endif /*EVENT_H_*/
