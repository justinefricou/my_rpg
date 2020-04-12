/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** define the dg_event struct
*/

#ifndef DG_EVENT_H_
#define DG_EVENT_H_

#include "dg_component.h"
#include "dg_array.h"

typedef struct dg_event
{
    int mouse_pressed_left;
    int mouse_pressed_right;
    int keyboard_pressed_up;
    int keyboard_pressed_down;
    int keyboard_pressed_left;
    int keyboard_pressed_right;
    int keyboard_pressed_space;
    int keyboard_pressed_enter;
    int keyboard_pressed_letter[26];
} dg_event_t;

#endif /*DG_EVENT_H*/
