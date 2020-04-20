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

static void status_set_pb(data_t *data, general_data_t *gd)
{
    dg_scene_add_ent(data->layer, ent_hud_progress_bar(
        (sfVector2f){650, 340}, 20, &(gd->player.pv), sfRed));
    dg_scene_add_ent(data->layer, ent_hud_progress_bar(
        (sfVector2f){650, 430}, 20, &(gd->player.pm), sfBlue));
    dg_scene_add_ent(data->layer, ent_hud_progress_bar(
        (sfVector2f){650, 520}, 20, &(gd->player.xp), sfGreen));
}

static void status_set_level(sfVector2f pos, int size,
    int nb, data_t *data)
{
    char text[4] = {0};

    text[0] = (nb >= 100) ? '0' + nb / 100 : ' ';
    text[1] = (nb >= 10) ? '0' + (nb / 10) % 10 : ' ';
    text[2] = '0' + nb % 10;
    dg_scene_add_ent(data->layer, ent_text(pos.x, pos.y, size, text));
}

static void status_set_money(sfVector2f pos, int size,
    int nb, data_t *data)
{
    char text[6] = {0};

    text[0] = (nb >= 10000) ? '0' + (nb / 10000) % 10 : ' ';
    text[1] = (nb >= 1000) ? '0' + (nb / 1000) % 10 : ' ';
    text[2] = (nb >= 100) ? '0' + (nb / 100) % 10 : ' ';
    text[3] = (nb >= 10) ? '0' + (nb / 10) % 10 : ' ';
    text[4] = '0' + nb % 10;
    dg_scene_add_ent(data->layer, ent_text(pos.x, pos.y, size, text));
}

static void status_set_skills(data_t *data, general_data_t *gd)
{
    status_set_level((sfVector2f){800, 650}, 30, 1, data);
    status_set_level((sfVector2f){800, 750}, 30, 1, data);
    status_set_level((sfVector2f){800, 850}, 30, 1, data);
    status_set_level((sfVector2f){1400, 650}, 30, 1, data);
    status_set_level((sfVector2f){1400, 750}, 30, 1, data);
    status_set_level((sfVector2f){1400, 850}, 30, 1, data);
}

void status_set_data(data_t *data, dg_window_t *w)
{
    general_data_t *gd = w->general_data;

    data->layer = scene_tmp_hover("status");
    status_set_pb(data, gd);
    dg_scene_add_ent(data->layer, ent_text(950, 30, 70, "STATUS"));
    dg_scene_add_ent(data->layer, ent_text(400, 150, 40, "name :"));
    dg_scene_add_ent(data->layer, ent_text(1500, 150, 40, "level :"));
    dg_scene_add_ent(data->layer, ent_text(950, 250, 40, "money :"));
    status_set_level((sfVector2f){1750, 140}, 50, gd->player.level, data);
    status_set_money((sfVector2f){1150, 240}, 50, gd->player.money, data);
    dg_scene_add_ent(data->layer, ent_text(570, 150, 40, gd->player.name));
    dg_scene_add_ent(data->layer, ent_text(400, 335, 40, "calm"));
    dg_scene_add_ent(data->layer, ent_text(400, 425, 40, "Strategy"));
    dg_scene_add_ent(data->layer, ent_text(400, 515, 40, "xp"));
    dg_scene_add_ent(data->layer, ent_text(600, 650, 30, "skill 1 :"));
    dg_scene_add_ent(data->layer, ent_text(600, 750, 30, "skill 2 :"));
    dg_scene_add_ent(data->layer, ent_text(600, 850, 30, "skill 3 :"));
    dg_scene_add_ent(data->layer, ent_text(1200, 650, 30, "skill 4 :"));
    dg_scene_add_ent(data->layer, ent_text(1200, 750, 30, "skill 5 :"));
    dg_scene_add_ent(data->layer, ent_text(1200, 850, 30, "skill 6 :"));
    status_set_skills(data, gd);
}