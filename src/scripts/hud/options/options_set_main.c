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
#include "hud/hud_options.h"
#include "epitech_tools.h"
#include "general_data.h"

static void opt_set_texts(data_t *data)
{
    data->content.main.name = ent_text(1000, 30, 75, "OPTIONS");
    data->content.volume_general.name = ent_text(620, 202, 30, "general");
    data->content.volume_music.name = ent_text(620, 282, 30, "music");
    data->content.volume_sound.name = ent_text(620, 362, 30, "sound");
}

void options_set_main(data_t *data, general_data_t *gd)
{
    opt_set_texts(data);
    data->content.main.data = ent_hud_box(490, 20, 29, 20);
    data->content.volume_general.data = ent_hud_progress_bar(
        (sfVector2f){800, 200}, 20, &(gd->options.general_volume), sfWhite);
    data->content.volume_music.data = ent_hud_progress_bar(
        (sfVector2f){800, 280}, 20, &(gd->options.music), sfWhite);
    data->content.volume_sound.data = ent_hud_progress_bar(
        (sfVector2f){800, 360}, 20, &(gd->options.sound), sfWhite);
    data->selector.entity = ent_sprite(
        dg_ressources_get_spritesheet_by_name("hud"),
        55, 3, (sfVector2f){535, 200});
}