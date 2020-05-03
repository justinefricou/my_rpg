/*
** EPITECH PROJECT, 2020
** script_monster
** File description:
** script player controller
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "hud/hud_status.h"

void status_data_add(data_t *data)
{
    dg_scene_add_ent(data->layer, ent_text(400, 335, 40, "calm"));
    dg_scene_add_ent(data->layer, ent_text(400, 425, 40, "Strategy"));
    dg_scene_add_ent(data->layer, ent_text(400, 515, 40, "xp"));
    dg_scene_add_ent(data->layer, ent_text(600, 650, 30, "skill 1 :"));
    dg_scene_add_ent(data->layer, ent_text(600, 750, 30, "skill 2 :"));
    dg_scene_add_ent(data->layer, ent_text(600, 850, 30, "skill 3 :"));
    dg_scene_add_ent(data->layer, ent_text(1200, 650, 30, "skill 4 :"));
    dg_scene_add_ent(data->layer, ent_text(1200, 750, 30, "skill 5 :"));
    dg_scene_add_ent(data->layer, ent_text(1200, 850, 30, "skill 6 :"));
}