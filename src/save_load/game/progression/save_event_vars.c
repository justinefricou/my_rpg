/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Saves the current progression regarding event variables.
*/

#include <stdio.h>
#include "save_load.h"

void save_event_vars(event_manager_t event_manager, FILE *save_file)
{
    write_str_in_save_file("event_vars_start\n", save_file);
    for (int i = 0; i < event_manager.var_len; i++) {
        write_int_in_save_file(event_manager.var[i].data, save_file);
        fwrite(" ", sizeof(char), 1, save_file);
        write_str_in_save_file(event_manager.var[i].name, save_file);
        fwrite("\n", sizeof(char), 1, save_file);
    }
    write_str_in_save_file("event_vars_end\n", save_file);
}