/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** hud
*/

#ifndef HUD_H_
#define HUD_H_

#include "script.h"

typedef struct button {
    char *name;
    void (*action)(dg_window_t *w);
} button_t;

#endif /*HUD_H_*/
