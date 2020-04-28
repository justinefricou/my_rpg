/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Saves the current progression regarding clues.
*/

#include <stdio.h>
#include "save_load.h"

void save_clues(clues_t clues, FILE *save_file)
{
    write_str_in_save_file("clues_start\n", save_file);
    write_str_in_save_file("len ", save_file);
    write_int_in_save_file(clues.len, save_file);
    fwrite("\n", sizeof(char), 1, save_file);
    for (int i = 0; i < clues.len; i++) {
        write_int_in_save_file(clues.list[i], save_file);
        fwrite("\n", sizeof(char), 1, save_file);
    }
    write_str_in_save_file("clues_end\n", save_file);
}