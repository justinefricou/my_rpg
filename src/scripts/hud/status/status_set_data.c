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

void status_set_sounds(data_t *data)
{
    data->sound_activate = dg_ressources_get_audio_by_name("hud_activate");
}

static void status_set_pb(data_t *data, general_data_t *gd)
{
    dg_scene_add_ent(data->layer, ent_hud_progress_bar(
        (sfVector2f){650, 250}, 20, &(gd->player.pv), sfRed));
    dg_scene_add_ent(data->layer, ent_hud_progress_bar(
        (sfVector2f){650, 340}, 20, &(gd->player.pm), sfBlue));
    dg_scene_add_ent(data->layer, ent_hud_progress_bar(
        (sfVector2f){650, 430}, 20, &(gd->player.xp), sfGreen));
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

static void status_set_skills(data_t *data, general_data_t *gd)
{
    status_set_level((sfVector2f){800, 600}, 30, 1, data);
    status_set_level((sfVector2f){800, 700}, 30, 1, data);
    status_set_level((sfVector2f){800, 800}, 30, 1, data);
    status_set_level((sfVector2f){1400, 600}, 30, 1, data);
    status_set_level((sfVector2f){1400, 700}, 30, 1, data);
    status_set_level((sfVector2f){1400, 800}, 30, 1, data);
}

void status_set_data(data_t *data, dg_window_t *w)
{
    general_data_t *gd = w->general_data;

    data->layer = scene_tmp_hover("status");
    status_set_pb(data, gd);
    dg_scene_add_ent(data->layer, ent_text(950, 30, 70, "STATUS"));
    dg_scene_add_ent(data->layer, ent_text(400, 150, 40, "name :"));
    dg_scene_add_ent(data->layer, ent_text(1500, 150, 40, "level :"));
    status_set_level((sfVector2f){1750, 140}, 50, gd->player.level, data);
    dg_scene_add_ent(data->layer, ent_text(570, 150, 40, gd->player.name));
    dg_scene_add_ent(data->layer, ent_text(400, 245, 40, "calm"));
    dg_scene_add_ent(data->layer, ent_text(400, 335, 40, "Strategy"));
    dg_scene_add_ent(data->layer, ent_text(400, 425, 40, "xp"));
    dg_scene_add_ent(data->layer, ent_text(600, 600, 30, "skill 1 :"));
    dg_scene_add_ent(data->layer, ent_text(600, 700, 30, "skill 2 :"));
    dg_scene_add_ent(data->layer, ent_text(600, 800, 30, "skill 3 :"));
    dg_scene_add_ent(data->layer, ent_text(1200, 600, 30, "skill 4 :"));
    dg_scene_add_ent(data->layer, ent_text(1200, 700, 30, "skill 5 :"));
    dg_scene_add_ent(data->layer, ent_text(1200, 800, 30, "skill 6 :"));
    status_set_skills(data, gd);
}