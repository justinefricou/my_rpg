/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** main
*/

#include "libdragon.h"
#include "ecs.h"
#include "general_data.h"

void unlock_clue(general_data_t *gd, int id)
{
    if (gd->clues.len >= CLUES_LEN)
        return;
    gd->clues.list[gd->clues.len] = id;
    gd->clues.len++;
}