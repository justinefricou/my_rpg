/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Loads a saved game's progression regarding event variables.
*/

#include <stdio.h>
#include <unistd.h>
#include "save_load.h"

static void set_next_var(char *line, event_manager_t *event_manager)
{
    int data = 0;

    data = get_nbr_until(line, ' ');
    for (; *line && *line != ' '; line++);
    line++;
    for (int i = 0; i < event_manager->var_len; i++) {
        if (my_strcmpp(line, event_manager->var[i].name) == 0) {
            event_manager->var[i].data = data;
            return;
        }
    }
    write(2, "Error : unknown event variable found.\n", 38);
}

static int load_event_vars(event_manager_t *event_manager, FILE *save_file)
{
    char *line = NULL;
    int end_of_event_vars = 0;

    while (!end_of_event_vars) {
        line = get_line_from_save_file(save_file);
        if (!line) {
            write(2, "Error : event variable could not be read.\n", 42);
            return (84);
        } else if (my_strcmpp(line, "event_vars_end") == 0) {
            end_of_event_vars = 1;
            free(line);
        } else {
            set_next_var(line, event_manager);
            free(line);
        }
    }
    return (0);
}

int load_saved_event_vars(event_manager_t *event_manager, FILE *save_file)
{
    char *line = NULL;

    line = get_line_from_save_file(save_file);
    if (!line || my_strcmpp(line, "event_vars_start") != 0) {
        write(2, "Error : events variables could not be loaded.\n", 46);
        if (line)
            free(line);
        return (84);
    }
    free(line);
    if (load_event_vars(event_manager, save_file) == 84)
        return (84);
    return (0);
}