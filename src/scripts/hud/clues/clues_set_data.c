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
#include "hud/hud_clues.h"

void clues_set_sounds(data_t *data)
{
    data->sound_activate = dg_ressources_get_audio_by_name("hud_activate");
    data->sound_move = dg_ressources_get_audio_by_name("hud_move");
}

void clues_set_data(data_t *data)
{
    dg_entity_t *ent = 0;

    dg_scene_add_ent(data->layer, ent_text(970, 20, 70, "CLUES"));
    for (int i = 0; i < 20; i++) {
        ent = ent_text(540, 140 + i * 40, 30, "");
        data->text[i] = dg_entity_get_component(ent, "text");
        dg_scene_add_ent(data->layer, ent);
    }
    sfText_setString(data->text[9],
    "                             -- NO CLUES --");
}

void scp_player_controller_end(void *data)
{
    data_t *d = (data_t *)data;

    free(d);
}