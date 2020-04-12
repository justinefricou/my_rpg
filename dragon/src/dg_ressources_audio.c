/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** dg_ressources_spritesheets
*/

#include <stdlib.h>
#include "libdragon.h"
#include "dg_ressources.h"
#include "epitech_tools.h"

static void indg_ressources_add_audio_two(dg_ressources_t *ressources,
    sfMusic *audio, char *name)
{
    ressources->audio.audio[ressources->audio.len] = audio;
    ressources->audio.audio[ressources->audio.len + 1] = 0;
    ressources->audio.name[ressources->audio.len] = name;
    ressources->audio.name[ressources->audio.len + 1] = 0;
    ressources->audio.len++;
}

void dg_ressources_add_audio(char *path, char *name)
{
    dg_ressources_t *ressources = dg_ressources();
    sfMusic **oldr = ressources->audio.audio;
    char **oldn = ressources->audio.name;
    sfMusic *audio = sfMusic_createFromFile(path);

    if (!audio)
        return;
    ressources->audio.audio = malloc(sizeof(sfMusic *) *
        (ressources->audio.len + 2));
    ressources->audio.name = malloc(sizeof(char *) *
        (ressources->audio.len + 2));
    for (int i = 0; i < ressources->audio.len; i++) {
        ressources->audio.audio[i] = oldr[i];
        ressources->audio.name[i] = oldn[i];
    }
    indg_ressources_add_audio_two(ressources, audio, name);
    free(oldr);
    free(oldn);
    
}

sfMusic *dg_ressources_get_audio(int id)
{
    dg_ressources_t *ressources = dg_ressources();

    if (ressources->audio.len <= id)
        return NULL;
    return ressources->audio.audio[id];
}

sfMusic *dg_ressources_get_audio_by_name(char *name)
{
    dg_ressources_t *ressources = dg_ressources();

    for (int i = 0; i < ressources->audio.len; i++)
        if (!dg_strcmp(ressources->audio.name[i], name))
            return ressources->audio.audio[i];
    return NULL;
}