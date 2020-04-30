/*
** EPITECH PROJECT, 2020
** attack_fight
** File description:
** attack_fight
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "hud/hud_inventory.h"

void skill_attack(int *previous, void *data, dg_window_t *w)
{
    general_data_t *gd = w->general_data;
    int i = &data;

    gd->enemy.pv.x -= gd->player.damage;
}