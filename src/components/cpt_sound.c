/*
** EPITECH PROJECT, 2020
** cpt_sound
** File description:
** cpt_sound
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "ecs.h"

void sound_play(sfMusic *sound)
{
    sfTime time = {0};

    sfMusic_setPlayingOffset(sound, time);
    sfMusic_play(sound);
}

static void cpt_sound_destroy(void *data)
{
    sfMusic *sound = (sfMusic *)(data);

    sfMusic_stop(sound);
    sfMusic_destroy(sound);
}

dg_component_t *cpt_sound(char *path)
{
    void (*destroy)(void *) = &cpt_sound_destroy;
    sfMusic *sound = sfMusic_createFromFile(path);

    dg_component_t *component = dg_component_create("sound", sound, destroy);
    sound_play(sound);
    return component;
}
