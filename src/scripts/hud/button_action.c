/*
** EPITECH PROJECT, 2020
** script_monster
** File description:
** script player controller
*/

#include "libdragon.h"

int action_quit(int *previous, void *data, dg_window_t *w)
{
    w->quit = 1;
}