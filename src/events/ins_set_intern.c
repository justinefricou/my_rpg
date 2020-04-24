/*
** EPITECH PROJECT, 2020
** background_menu
** File description:
** background_menu
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "libmy.h"
#include "general_data.h"
#include "instructions.h"

static const key_setter_t key_setter[14] = {
    NULL, &ins_set_set, &ins_set_if, &ins_set_while, &ins_set_for,
    &ins_set_end, &ins_set_give, &ins_set_take, &ins_set_tp, &ins_set_dialog,
    &ins_set_talk, &ins_set_answer, &ins_set_battle, &ins_set_move};

instruction_t *ins_set_intern(instruction_t *tmp, int *i,
    general_data_t *gd)
{
    instruction_t *instructions = malloc(sizeof(instruction_t));
    instruction_t to_add = {0};
    int len = 0;

    for (*i += 1; tmp[*i].keycode != END; *i += 1) {
        to_add.keycode = tmp[*i].keycode;
        if (key_setter[tmp[*i].keycode])
            to_add.parameters = key_setter[tmp[*i].keycode]
                (tmp, i, gd, &(to_add.len));
        else
            to_add.parameters = NULL;
        instructions = add_instruction(instructions, len, to_add);
    }
    *i++;
    return instructions;
}