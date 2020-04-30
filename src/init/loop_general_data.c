/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "general_data.h"
#include "save_load.h"

void fix_empty_slot(general_data_t *gd, int hole)
{
    for (; hole + 1 < gd->inventory.len; hole++) {
        gd->inventory.slot[hole].id = gd->inventory.slot[hole + 1].id;
        gd->inventory.slot[hole].nb = gd->inventory.slot[hole + 1].nb;
    }
    gd->inventory.slot[hole].id = -1;
    gd->inventory.slot[hole].nb = 0;
    gd->inventory.len--;
}

void update_inventory(general_data_t *gd)
{
    int *id = 0;
    int *nb = 0;

    for (int i = 0; i < gd->inventory.len; i++) {
        id = &(gd->inventory.slot[i].id);
        nb = &(gd->inventory.slot[i].nb);
        *id = (*nb == 0) ? -1 : *id;
        if (*id == -1)
            fix_empty_slot(gd, i);
    }
}

void update_level(general_data_t *gd)
{
    int x = gd->player.level;
    int ran = 0;

    if (gd->player.level >= 100) {
        gd->player.xp.x = 0;
        return;
    }
    gd->player.xp.y = 10 + 4 * x - x * x * 0.01;
    if (gd->player.xp.x >= gd->player.xp.y) {
        gd->player.level++;
        gd->player.xp.x = 0;
        for (int i = 0; i < 3; i++) {
            ran = rand() % 4;
            //add stat later
        }
    }
}