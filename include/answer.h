/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** objects
*/

#ifndef GIVE_H_
#define GIVE_H_

#include "libdragon.h"
#include "general_data.h"
#include "event.h"
#include "hud/hud.h"
#include "script_event_data.h"

button_t *set_choices(intern_t *prev, intern_t *intern);
void dialog_button(int *previous, void *data, dg_window_t *w);

#endif /*GIVE_H_*/