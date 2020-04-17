/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Saves player's inventory.
*/

#include <stdio.h>
#include "save_load.h"

void save_inventory(inventory_t inventory, FILE *save_file)
{
    write_str_in_save_file("inventory\n", save_file);
    write_int_in_save_file(inventory.len, save_file);
    fwrite("\n", sizeof(char), 1, save_file);
    for (int i = 0; i < inventory.len; i++)
        save_inventory_slot(inventory.slot[i], save_file);
}

void save_inventory_slot(inventory_slot_t inventory_slot, FILE *save_file)
{

}