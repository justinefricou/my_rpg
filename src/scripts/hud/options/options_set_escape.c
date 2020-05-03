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
    data->content.main.name = ent_text(930, 30, 75, "OPTIONS");
    data->content.volume_general.name = ent_text(480, 202, 30, "general");
    data->content.volume_music.name = ent_text(480, 282, 30, "music");
    data->content.volume_sound.name = ent_text(480, 362, 30, "sound");
    data->content.keymap_action.name = ent_text(480, 442, 30, "action");
    data->content.keymap_cancel.name = ent_text(480, 522, 30, "cancel");
    data->content.keymap_up.name = ent_text(480, 602, 30, "up");
    data->content.keymap_down.name = ent_text(480, 682, 30, "down");
    data->content.keymap_left.name = ent_text(480, 762, 30, "left");
    data->content.keymap_right.name = ent_text(480, 842, 30, "right");
    data->content.language.name = ent_text(480, 922, 30, "language");
}

static void opt_set_km(data_t *data, general_data_t *gd)
{
    data->content.keymap_down.data = ent_hud_keymap_button(
        (sfVector2f){660, 600}, 6, &(gd->options.keymap.up),
        data->hover_layer);
    data->content.keymap_left.data = ent_hud_keymap_button(
        (sfVector2f){660, 680}, 6, &(gd->options.keymap.down),
        data->hover_layer);
    data->content.keymap_right.data = ent_hud_keymap_button(
        (sfVector2f){660, 760}, 6, &(gd->options.keymap.left),
        data->hover_layer);
    data->content.keymap_up.data = ent_hud_keymap_button(
        (sfVector2f){660, 840}, 6, &(gd->options.keymap.right),
        data->hover_layer);
    data->content.language.data = ent_hud_language_button(
        (sfVector2f){660, 920}, 6, data->hover_layer);
}

void options_set_escape(data_t *data, general_data_t *gd)
{
    opt_set_texts(data);
    data->content.main.data = ent_hud_box(350, 20, 32, 20);
    data->content.volume_general.data = ent_hud_progress_bar(
        (sfVector2f){660, 200}, 24, &(gd->options.general_volume), sfWhite);
    data->content.volume_music.data = ent_hud_progress_bar(
        (sfVector2f){660, 280}, 24, &(gd->options.music), sfWhite);
    data->content.volume_sound.data = ent_hud_progress_bar(
        (sfVector2f){660, 360}, 24, &(gd->options.sound), sfWhite);
    data->content.keymap_action.data = ent_hud_keymap_button(
        (sfVector2f){660, 440}, 6, &(gd->options.keymap.action),
        data->hover_layer);
    data->content.keymap_cancel.data = ent_hud_keymap_button(
        (sfVector2f){660, 520}, 6, &(gd->options.keymap.cancel),
        data->hover_layer);
    opt_set_km(data, gd);
    data->selector.entity = ent_sprite(
        dg_ressources_get_spritesheet_by_name("hud"),
        55, 3, (sfVector2f){400, 200});
}