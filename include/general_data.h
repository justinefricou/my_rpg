/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** epitech forbidden functions
*/

#ifndef GENERAL_DATA_H_
#define GENERAL_DATA_H_

typedef struct general_data
{

} general_data_t;

typedef struct game_data
{
    int build_id;
    int can_spawn_tower;
    int money;
    int wave;
    int health;
} game_data_t;

static const int COST[4] = {5, 10, 20, 30};

#endif /*GENERAL_DATA_H_*/
