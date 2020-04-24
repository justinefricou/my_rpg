/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** Initializes general data when starting a new game.
*/

#include "general_data.h"

static void init_inventory_for_new_game(inventory_t *inventory)
{
    inventory->len = 0;
    inventory->stack.x = 0;
    inventory->stack.y = 100;
}

static void init_clues_for_new_game()
{
    // TODO
}

static void init_player_for_new_game(player_t *player)
{
    player->name = "Player";
    player->pv.x = 90;
    player->pv.y = 100;
    player->pm.x = 90;
    player->pm.y = 100;
    player->level = 0;
    player->xp.x = 0;
    player->xp.y = 100;
    player->money = 100;
}

void init_general_data_for_new_game(general_data_t *data)
{
    init_inventory(&(data->inventory));
    init_clues();
    init_player(&(data->player));
}