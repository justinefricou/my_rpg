/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** define the dg_ressources struct
*/

#ifndef DG_RESSOURCES_H_
#define DG_RESSOURCES_H_

#include "dg_spritesheet.h"
#include <SFML/Graphics.h>

typedef struct dg_ressources_audio
{
    sfMusic **audio;
    char **name;
    int len;
} dg_ressources_audio_t;

typedef struct dg_ressources_sheet
{
    dg_spritesheet_t **sheets;
    char **name;
    int len;
} dg_ressources_sheet_t;

typedef struct dg_ressources
{
    dg_ressources_sheet_t sheets;
    dg_ressources_audio_t audio;
} dg_ressources_t;

dg_ressources_t *dg_ressources(void);

void dg_ressources_destroy(void);

//spritesheets
void dg_ressources_add_spritesheet(char *path, char *name,
    int width, int height);
dg_spritesheet_t *dg_ressources_get_spritesheet(int);
dg_spritesheet_t *dg_ressources_get_spritesheet_by_name(char *name);

//audio
void dg_ressources_add_audio(char *path, char *name);
sfMusic *dg_ressources_get_audio(int id);
sfMusic *dg_ressources_get_audio_by_name(char *name);

#endif /*DG_RESSOURCES_H*/
