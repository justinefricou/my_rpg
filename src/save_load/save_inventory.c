/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Saves player's inventory.
*/

#include <stdio.h>
#include "save_load.h"

static void save_inventory_slot(inventory_slot_t slot, FILE *save_file)
{
    write_int_in_save_file(slot.id, save_file);
    fwrite(" ", sizeof(char), 1, save_file);
    write_int_in_save_file(slot.nb, save_file);
    fwrite("\n", sizeof(char), 1, save_file);
}

void save_inventory(inventory_t inventory, FILE *save_file)
{
    write_str_in_save_file("inventory_start\n", save_file);
    write_str_in_save_file("max_len ", save_file);
    write_int_in_save_file(inventory.max_len, save_file);
    fwrite("\n", sizeof(char), 1, save_file);
    write_str_in_save_file("len ", save_file);
    write_int_in_save_file(inventory.len, save_file);
    fwrite("\n", sizeof(char), 1, save_file);
    for (int i = 0; i < inventory.len; i++)
        save_inventory_slot(inventory.slot[i], save_file);
    write_str_in_save_file("inventory_end\n", save_file);
}