/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** dg_roussrces.c
*/

#include <stdlib.h>
#include "libdragon.h"
#include "dragon/dg_ressources.h"

dg_ressources_t *dg_ressources(void)
{
    static dg_ressources_t ressources = {0};

    if (!ressources.sheets.sheets) {
        ressources.sheets.sheets = malloc(sizeof(dg_spritesheet_t *));
        ressources.sheets.sheets[0] = 0;
        ressources.sheets.name = malloc(sizeof(char *));
        ressources.sheets.name[0] = 0;
        ressources.sheets.len = 0;
        ressources.audio.audio = malloc(sizeof(sfMusic *));
        ressources.audio.audio[0] = 0;
        ressources.audio.name = malloc(sizeof(char *));
        ressources.audio.name[0] = 0;
        ressources.audio.len = 0;
    }
    return &ressources;
}

void dg_ressources_destroy(void)
{
    dg_ressources_t *ressources = dg_ressources();

    for (int i = 0; i < ressources->sheets.len; i++)
        dg_spritesheet_free(ressources->sheets.sheets[i]);
    for (int i = 0; i < ressources->audio.len; i++)
        sfMusic_destroy(ressources->audio.audio[i]);
    free(ressources->sheets.sheets);
    free(ressources->sheets.name);
    free(ressources->audio.audio);
    free(ressources->audio.name);
}
