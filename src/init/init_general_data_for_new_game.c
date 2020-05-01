/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** Initializes general data when starting a new game.
*/

#include "general_data.h"
#include "init_general_data_for_new_game.h"
#include "event.h"

static void init_inventory_for_new_game(inventory_t *inventory)
{
    inventory->len = 0;
    inventory->stack.x = 0;
    inventory->stack.y = 100;
}

static void init_clues_for_new_game(clues_t *clues)
{
    clues->len = 0;
    for (int i = 0; i < CLUES_LEN; i++)
        clues->list[i] = 0;
}

static void init_player_for_new_game(player_t *player)
{
    player->name = "Player";
    player->pv.x = 90;
    player->pv.y = 100;
    player->pm.x = 90;
    player->pm.y = 100;
    player->level = 1;
    player->xp.x = 0;
    player->xp.y = 100;
    player->money = 100;
    player->damage = 10;
}

static void init_event_vars_for_new_game(event_manager_t *event_manager)
{
    for (int i = 0; i < event_manager->var_len; i++)
        event_manager->var[i].data = 0;
}

void init_general_data_for_new_game(general_data_t *data)
{
    init_inventory_for_new_game(&(data->inventory));
    init_clues_for_new_game(&(data->clues));
    init_player_for_new_game(&(data->player));
    init_event_vars_for_new_game(&(data->event_manager));
}