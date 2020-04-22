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
#include "hud/hud_save.h"

void save_set_sounds(data_t *data)
{
    data->sound_activate = dg_ressources_get_audio_by_name("hud_activate");
    data->sound_move = dg_ressources_get_audio_by_name("hud_move");
}

static void save_add_info(data_t *data, int x, int y, int i)
{
    char slot_name[7] = {'s', 'l', 'o', 't', ' ', '1' + i, '\0'};

    dg_scene_add_ent(data->layer, ent_text(x + 25, y + 10, 60, slot_name));
    dg_scene_add_ent(data->layer, ent_text(x + 25, y + 140, 60, "Player"));
    dg_scene_add_ent(data->layer, ent_text(x + 1110, y + 75, 60, "lvl :"));
    dg_scene_add_ent(data->layer, ent_text(x + 1310, y + 75, 60, "100"));
}

void save_set_data(data_t *data, dg_scene_t *scene)
{
    dg_scene_add_ent(data->layer, ent_text(1000, 50, 70, "SAVE"));
    for (int i = 0; i < 3; i++) {
        data->hud_box[i] = ent_hud_box(350, 190 + i * 270, 32, 5);
        dg_scene_add_ent(scene, data->hud_box[i]);
        save_add_info(data, 350, 190 + i * 270, i);
    }
    data->hud_box[3] = ent_hud_box(350, 50, 32, 2);
    dg_scene_add_ent(scene, data->hud_box[3]);
}