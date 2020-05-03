/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** main
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "general_data.h"

static int *get_dgkey_id_letter(dg_window_t *w, sfKeyCode key)
{
    if (key >= sfKeyA && key <= sfKeyZ)
        return &(w->events.keyboard_pressed_letter[key]);
}

static int *get_dgkey_id(dg_window_t *w, sfKeyCode key)
{
    switch (key)
    {
        case sfKeyEscape:
            return &(w->events.keyboard_pressed_escape);
        case sfKeySpace:
            return &(w->events.keyboard_pressed_space);
        case sfKeyEnter:
            return &(w->events.keyboard_pressed_enter);
        case sfKeyUp:
            return &(w->events.keyboard_pressed_up);
        case sfKeyLeft:
            return &(w->events.keyboard_pressed_left);
        case sfKeyRight:
            return &(w->events.keyboard_pressed_right);
        case sfKeyDown:
            return &(w->events.keyboard_pressed_down);
        default:
            return get_dgkey_id_letter(w, key);
    }
}

int is_mouse_clicked(dg_window_t *w, char *key, int force_ignore)
{
    if (!dg_strcmp("action", key) && w->events.mouse_pressed_left) {
        if (force_ignore)
            w->events.mouse_pressed_left = 0;
        return 1;
    }
    if (!dg_strcmp("cancel", key) && w->events.mouse_pressed_right) {
        if (force_ignore)
            w->events.mouse_pressed_right = 0;
        return 1;
    }
    return 0;
}

int key_is_clicked(dg_window_t *w, sfKeyCode key, int force_ignore)
{
    int *result = NULL;
    int tr = 0;

    result = get_dgkey_id(w, key);
    if (!result)
        return 0;
        tr = *result;
    if (force_ignore)
        *result = 0;
    return tr;
}