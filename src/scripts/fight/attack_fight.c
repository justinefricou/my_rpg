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
    dg_scene_t *scene = dg_scene_manager_get_scene("layer_hud_fight");
    general_data_t *gd = w->general_data;
    int i = *((int *)data);
    float mult = 1;

    dg_scene_add_ent(scene, ent_hud_fight_dialogue(previous, scene, i, gd));
    if (gd->skills[i].type == gd->enemy.type ||
        -2 == (gd->enemy.type - gd->skills[i].type) ||
        2 == (gd->enemy.type - gd->skills[i].type))
        mult = 1;
    else if (-1 == (gd->enemy.type - gd->skills[i].type))
        mult = 2;
    else
        mult = 0.5;
    gd->enemy.pv.x -= (gd->player.damage * mult);
}