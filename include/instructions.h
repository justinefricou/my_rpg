/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** event function
*/

#include "libdragon.h"
#include "general_data.h"

#ifndef INSTRUCTIONS_H_
#define INSTRUCTIONS_H_

typedef parameters_t *(*key_setter_t)(instruction_t *, int *, general_data_t *);

//ins_setter
parameters_t *ins_set_set(instruction_t *instruction, int *i,
    general_data_t *gd);
parameters_t *ins_set_if(instruction_t *instruction, int *i,
    general_data_t *gd);
parameters_t *ins_set_while(instruction_t *instruction, int *i,
    general_data_t *gd);
parameters_t *ins_set_for(instruction_t *instruction, int *i,
    general_data_t *gd);
parameters_t *ins_set_end(instruction_t *instruction, int *i,
    general_data_t *gd);
parameters_t *ins_set_give(instruction_t *instruction, int *i,
    general_data_t *gd);
parameters_t *ins_set_take(instruction_t *instruction, int *i,
    general_data_t *gd);
parameters_t *ins_set_tp(instruction_t *instruction, int *i,
    general_data_t *gd);
parameters_t *ins_set_dialog(instruction_t *instruction, int *i,
    general_data_t *gd);
parameters_t *ins_set_talk(instruction_t *instruction, int *i,
    general_data_t *gd);
parameters_t *ins_set_answer(instruction_t *instruction, int *i,
    general_data_t *gd);
parameters_t *ins_set_battle(instruction_t *instruction, int *i,
    general_data_t *gd);
parameters_t *ins_set_move(instruction_t *instruction, int *i,
    general_data_t *gd);

//functions
void set_variable(variable_t *var, int i, void *data);
void *get_variable(variable_t *var, int i);
int variable_to_int(char *name, general_data_t *gd);
int type_from_str(char *text);
parameters_t set_from_calcul(char *data, general_data_t *gd);
instruction_t *ins_set_intern(instruction_t *instruction, int *i,
    general_data_t *gd);
instruction_t *add_instruction(instruction_t *old,
    int len, instruction_t data);

//parser
char *set_event_path(char *filename);
int get_event_content(char **content, int fd);
int open_event_file(char *filename, int *fd);
instruction_t *create_event(char *content, int *len);
event_t *set_text_events(void);

#endif /*INSTRUCTIONS_H_*/
