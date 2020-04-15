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

static void indg_ressources_add_spritesheet_two(dg_ressources_t *ressources,
    dg_spritesheet_t *sheet, char *name)
{
    ressources->sheets.sheets[ressources->sheets.len] = sheet;
    ressources->sheets.sheets[ressources->sheets.len + 1] = 0;
    ressources->sheets.name[ressources->sheets.len] = name;
    ressources->sheets.name[ressources->sheets.len + 1] = 0;
    ressources->sheets.len++;
}

void dg_ressources_add_spritesheet(char *path, char *name,
    int width, int height)
{
    dg_ressources_t *ressources = dg_ressources();
    dg_spritesheet_t **oldr = ressources->sheets.sheets;
    char **oldn = ressources->sheets.name;
    dg_spritesheet_t *sheet = dg_spritesheet_create(path, width, height);

    if (!sheet)
        return;
    ressources->sheets.sheets = malloc(sizeof(sfMusic *) *
        (ressources->sheets.len + 2));
    ressources->sheets.name = malloc(sizeof(char *) *
        (ressources->sheets.len + 2));
    for (int i = 0; i < ressources->sheets.len; i++) {
        ressources->sheets.sheets[i] = oldr[i];
        ressources->sheets.name[i] = oldn[i];
    }
    indg_ressources_add_spritesheet_two(ressources, sheet, name);
    free(oldr);
    free(oldn);
}

dg_spritesheet_t *dg_ressources_get_spritesheet(int id)
{
    dg_ressources_t *ressources = dg_ressources();

    if (ressources->sheets.len <= id)
        return NULL;
    return ressources->sheets.sheets[id];
}

dg_spritesheet_t *dg_ressources_get_spritesheet_by_name(char *name)
{
    dg_ressources_t *ressources = dg_ressources();

    for (int i = 0; i < ressources->sheets.len; i++)
        if (!dg_strcmp(ressources->sheets.name[i], name))
            return ressources->sheets.sheets[i];
    return NULL;
}