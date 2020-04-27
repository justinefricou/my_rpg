/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Loads a saved game's progression regarding clues.
*/

#include <stdio.h>
#include <unistd.h>
#include "save_load.h"

static int load_clues_len(clues_t *clues, FILE *save_file)
{
    char *line = NULL;
    int start = 0;

    line = get_line_from_save_file(save_file);
    if (!line) {
        write(2, "Error : clues number could not be loaded.\n", 42);
        return (84);
    }
    start = my_strlen("len ");
    clues->len = get_nbr_until(&(line[start]), 0);
    free(line);
    return (0);
}

static int load_clue(int *clue, FILE *save_file)
{
    char *line = NULL;
    int start = 0;

    line = get_line_from_save_file(save_file);
    if (!line)
        return (0);
    *clue = get_nbr_until(line, 0);
    free(line);
    return (1);
}

static int load_clues(clues_t *clues, FILE *save_file)
{
    char *line = NULL;

    for (int i = 0; i < clues->len; i++) {
        if (!load_clue(&(clues->list[i]), save_file)) {
            write(2, "Error : clue could not be loaded.\n", 34);
            return (84);
        }
    }
    line = get_line_from_save_file(save_file);
    if (!line || my_strcmpp(line, "clues_end") != 0) {
        write(2, "Error : too many clues found in file.\n", 38);
        if (line)
            free(line);
        return (84);
    }
    for (int i = clues->len; i < CLUES_LEN; i++)
        clues->list[i] = 0;
    free(line);
    return (0);
}

int load_saved_clues(clues_t *clues, FILE *save_file)
{
    char *line = NULL;

    line = get_line_from_save_file(save_file);
    if (!line || my_strcmpp(line, "clues_start") != 0) {
        write(2, "Error : clues could not be loaded.\n", 35);
        if (line)
            free(line);
        return (84);
    }
    free(line);
    if (load_clues_len(clues, save_file) == 84)
        return (84);
    if (load_clues(clues, save_file) == 84)
        return (84);
    return (0);
}