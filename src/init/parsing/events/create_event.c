/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** map
*/

#include <dirent.h>
#include <sys/types.h>
#include "libmy.h"
#include "libdragon.h"
#include "map.h"
#include "general_data.h"
#include "event.h"
#include <stdlib.h>
#include <stdio.h>
#include "epitech_tools.h"
#include <unistd.h>

static const char *key_text[14] = {"NONE", "SET", "IF", "WHILE", "FOR",
    "END", "GIVE", "TAKE", "TP", "DIALOG", "TALK", "ANSWER", "BATTLE", "MOVE"};

static char *parse_instructions(int *i, char *content)
{
    char *result = NULL;
    int len = 0;

    for (; content[*i + len] != ' ' && content[*i + len] != '\n'
        && content[*i + len] != '\0';
        len++);
    result = malloc(sizeof(char) * (len + 1));
    for (int j = 0; j < len; j++) {
        result[j] = content[*i + j];
    }
    result[len] = 0;
    *i += len;
    return result;
}

int text_to_kk(char *kk_text)
{
    for (int i = 0; i < 14; i++) {
        if (!dg_strcmp(kk_text, key_text[i]))
            return i;
    }
    return NONE;
}

static int set_instructions_text(char *content, int *i,
    instruction_t *instruction)
{
    parameters_t *tmp = 0;
    int len = 0;

    while (content[*i] != '\n' && content[*i]) {
        tmp = instruction->parameters;
        instruction->parameters = malloc(sizeof(parameters_t) * (len + 2));
        for (int j = 0; j < len; j++)
            instruction->parameters[j] = tmp[j];
        instruction->parameters[len].type = STRING;
        if (content[*i])
            *i += 1;
        instruction->parameters[len].parameters.s =
            parse_instructions(i, content);
        len++;
        free(tmp);
    }
    return len;
}

instruction_t get_instructions(int *i, char *content)
{
    instruction_t instruction;
    int len = 0;
    char *kk_text = parse_instructions(i, content);

    instruction.keycode = text_to_kk(kk_text);
    instruction.parameters = malloc(sizeof(parameters_t));
    free(kk_text);
    len = set_instructions_text(content, i, &instruction);
    if (content[*i])
        *i += 1;
    instruction.parameters[len].type = VOID;
    instruction.len = len;
    return instruction;
}

instruction_t *create_event(char *content, int *len)
{
    instruction_t *instructions = 0;
    instruction_t *tmp = 0;

    for (int i = 0; content[i];) {
        tmp = malloc(sizeof(instruction_t) * (*len + 2));
        for (int j = 0; j < *len; j++)
            tmp[j] = instructions[j];
        tmp[*len] = get_instructions(&i, content);
        if (instructions)
            free(instructions);
        instructions = tmp;
        *len += 1;
    }
    instructions[*len].keycode = NONE;
    return instructions;
}