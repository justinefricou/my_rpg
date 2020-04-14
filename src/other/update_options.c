/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** main
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "general_data.h"

void set_volume(dg_window_t *w)
{
    sfMusic *audio = 0;
    int type = 0;
    dg_ressources_t *res = dg_ressources();
    general_data_t *gd = (general_data_t *)(w->general_data);

    for (int i = 0; i < res->audio.len; i++) {
        audio = res->audio.audio[i];
        type = res->audio.type[i];
        if (type == 0)
            sfMusic_setVolume(audio, gd->options.music);
        else
            sfMusic_setVolume(audio, gd->options.sound);
    }
    if (gd->options.music > gd->options.general_volume)
        gd->options.music = gd->options.general_volume;
    if (gd->options.sound > gd->options.general_volume)
        gd->options.sound = gd->options.general_volume;
}