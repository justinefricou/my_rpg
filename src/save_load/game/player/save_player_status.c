/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Saves player's status : health points and money.
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/System/Vector2.h>
#include "libmy.h"
#include "save_load.h"

void save_player_pv(sfVector2f pv, FILE *save_file)
{
    write_str_in_save_file("current_pv ", save_file);
    write_int_in_save_file(pv.x, save_file);
    fwrite("\n", sizeof(char), 1, save_file);
    write_str_in_save_file("max_pv ", save_file);
    write_int_in_save_file(pv.y, save_file);
    fwrite("\n", sizeof(char), 1, save_file);
}

void save_player_pm(sfVector2f pm, FILE *save_file)
{
    write_str_in_save_file("current_pm ", save_file);
    write_int_in_save_file(pm.x, save_file);
    fwrite("\n", sizeof(char), 1, save_file);
    write_str_in_save_file("max_pm ", save_file);
    write_int_in_save_file(pm.y, save_file);
    fwrite("\n", sizeof(char), 1, save_file);
}

void save_player_money(player_t player, FILE *save_file)
{
    write_str_in_save_file("player_money ", save_file);
    write_int_in_save_file(player.money, save_file);
    fwrite("\n", sizeof(char), 1, save_file);
}