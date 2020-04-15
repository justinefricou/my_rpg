/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** hud
*/

#ifndef HUD_H_
#define HUD_H_

#include "libdragon.h"

typedef void (*button_action_t)(int *, void *, dg_window_t *);

typedef struct button {
    char *name;
    button_action_t action;
    void *data;
} button_t;

#endif /*HUD_H_*/
