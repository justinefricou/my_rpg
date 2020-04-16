/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** hud keymap button
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"

static const char *letters[26] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I",
    "J", "K", "L", "M", "N", "O", "P", "Q", "R",
    "S", "T", "U", "V", "W", "X", "Y", "Z"};

const char *keycode_to_text(sfKeyCode code)
{
    if (code >= sfKeyA && code <= sfKeyZ)
        return letters[code];
    switch (code) {
        case sfKeyUp:
            return "up";
        case sfKeyDown:
            return "down";
        case sfKeyLeft:
            return "left";
        case sfKeyRight:
            return "right";
        case sfKeyEnter:
            return "Enter";
        case sfKeyEscape:
            return "Escape";
        case sfKeySpace:
            return "Space";
    }
    return "";
}