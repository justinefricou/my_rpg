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

void act_by_selected(data_t *data)
{
    hud_progress_bar_activate(data->content.volume_general.data, 0);
    hud_progress_bar_activate(data->content.volume_music.data, 0);
    hud_progress_bar_activate(data->content.volume_sound.data, 0);
    (data->select == 0) ?
        hud_progress_bar_activate(data->content.volume_general.data, 1) : NULL;
    (data->select == 1) ?
        hud_progress_bar_activate(data->content.volume_music.data, 1) : NULL;
    (data->select == 2) ?
        hud_progress_bar_activate(data->content.volume_sound.data, 1) : NULL;
}

float update_selector(data_t *data)
{
    switch (data->select)
    {
        case 0:
            return 200;
        case 1:
            return 280;
        case 2:
            return 360;
    }
    return 0;
}

void update_sound(data_t *data, general_data_t *gd)
{
    float gvm = gd->options.general_volume.x;

    if (data->gvm != gvm) {
        gd->options.music.x += gvm - data->gvm;
        gd->options.sound.x += gvm - data->gvm;
        data->gvm = gvm;
    }
    gd->options.music.x = (gd->options.music.x < 0) ? 0 : gd->options.music.x;
    gd->options.sound.x = (gd->options.sound.x < 0) ? 0 : gd->options.sound.x;
    gd->options.music.x = (gd->options.music.x > 100) ?
        100 : gd->options.music.x;
    gd->options.sound.x = (gd->options.sound.x > 100) ?
        100 : gd->options.sound.x;
}