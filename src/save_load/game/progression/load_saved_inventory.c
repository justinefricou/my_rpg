/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Loads player's inventory from a save.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libmy.h"
#include "save_load.h"

static int load_inventory_weights(inventory_t *inventory, FILE *save_file)
{
    char *line = NULL;
    int start = 0;

    line = get_line_from_save_file(save_file);
    if (!line) {
        write(2, "Error : inventory's max weight could not be loaded.\n", 52);
        return (84);
    }
    start = my_strlen("max_weight ");
    inventory->stack.y = get_nbr_until(&(line[start]), 0);
    free(line);
    line = get_line_from_save_file(save_file);
    if (!line) {
        write(2, "Error : inventory's weight could not be loaded.\n", 48);
        return (84);
    }
    start = my_strlen("current_weight ");
    inventory->stack.x = get_nbr_until(&(line[start]), 0);
    free(line);
    return (0);
}

static int load_inventory_len(inventory_t *inventory, FILE *save_file)
{
    char *line = NULL;
    int start = 0;

    line = get_line_from_save_file(save_file);
    if (!line) {
        write(2, "Error : inventory's length could not be loaded.\n", 48);
        return (84);
    }
    start = my_strlen("len ");
    inventory->len = get_nbr_until(&(line[start]), 0);
    free(line);
    return (0);
}

static int load_inventory_slot(inventory_slot_t *slot, FILE *save_file)
{
    char *line = NULL;
    int start = 0;

    line = get_line_from_save_file(save_file);
    if (!line)
        return (0);
    slot->id = get_nbr_until(line, ' ');
    for (; line[start] && line[start] != ' '; start++);
    slot->nb = get_nbr_until(&(line[start + 1]), 0);
    free(line);
    return (1);
}

static int load_inventory_content(inventory_t *inventory, FILE *save_file)
{
    char *line = NULL;

    for (int i = 0; i < inventory->len; i++) {
        if (!load_inventory_slot(&(inventory->slot[i]), save_file)) {
            write(2, "Error : inventory slot could not be loaded.\n", 44);
            return (84);
        }
    }
    line = get_line_from_save_file(save_file);
    if (!line || my_strcmpp(line, "inventory_end") != 0) {
        write(2, "Error : too many inventory objects found in file.\n", 50);
        if (line)
            free(line);
        return (84);
    }
    free(line);
    return (0);
}

int load_saved_inventory(inventory_t *inventory, FILE *save_file)
{
    char *line = NULL;

    line = get_line_from_save_file(save_file);
    if (!line || my_strcmpp(line, "inventory_start") != 0) {
        write(2, "Error : inventory could not be loaded.\n", 39);
        if (line)
            free(line);
        return (84);
    }
    free(line);
    if (load_inventory_weights(inventory, save_file) == 84)
        return (84);
    if (load_inventory_len(inventory, save_file) == 84)
        return (84);
    if (load_inventory_content(inventory, save_file) == 84)
        return (84);
    return (0);
}