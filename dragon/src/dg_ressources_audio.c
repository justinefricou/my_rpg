/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** dg_ressources_spritesheets
*/

#include <stdlib.h>
#include "libdragon.h"
#include "dragon/dg_ressources.h"
#include "epitech_tools.h"

static void indg_ressources_add_audio_two(dg_ressources_t *ressources,
    sfMusic *audio, char *name, int type)
{
    ressources->audio.audio[ressources->audio.len] = audio;
    ressources->audio.audio[ressources->audio.len + 1] = 0;
    ressources->audio.name[ressources->audio.len] = name;
    ressources->audio.name[ressources->audio.len + 1] = 0;
    ressources->audio.type[ressources->audio.len] = type;
    ressources->audio.type[ressources->audio.len + 1] = -1;
    ressources->audio.len++;
}

static void indg_ressources_malloc_audio(dg_ressources_t *ressources)
{
    ressources->audio.audio = malloc(sizeof(sfMusic *) *
        (ressources->audio.len + 2));
    ressources->audio.name = malloc(sizeof(char *) *
        (ressources->audio.len + 2));
    ressources->audio.type = malloc(sizeof(int *) *
        (ressources->audio.len + 2));
}

void dg_ressources_add_audio(char *path, char *name, int type)
{
    dg_ressources_t *ressources = dg_ressources();
    sfMusic **oldr = ressources->audio.audio;
    char **oldn = ressources->audio.name;
    int *oldt = ressources->audio.type;
    sfMusic *audio = sfMusic_createFromFile(path);

    if (!audio)
        return;
    indg_ressources_malloc_audio(ressources);
    for (int i = 0; i < ressources->audio.len; i++) {
        ressources->audio.audio[i] = oldr[i];
        ressources->audio.name[i] = oldn[i];
        ressources->audio.type[i] = oldt[i];
    }
    indg_ressources_add_audio_two(ressources, audio, name, type);
    free(oldr);
    free(oldn);
    free(oldt);   
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