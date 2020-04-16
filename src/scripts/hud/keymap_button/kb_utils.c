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
#include "hud/hud_keymap_button.h"

void hud_keymap_button_activate(dg_entity_t *kb, int stat)
{
    script_t *script = (script_t *)dg_entity_get_component(kb, "script");
    data_t *data = script->data;

    data->active = stat;
}

int is_valid_key(sfKeyCode key)
{
    int rtv = 0;

    if (key >= sfKeyA && key <= sfKeyZ)
        rtv += 1;
    rtv += (key == sfKeyEnter) ? 1 : 0;
    rtv += (key == sfKeySpace) ? 1 : 0;
    rtv += (key == sfKeyUp) ? 1 : 0;
    rtv += (key == sfKeyDown) ? 1 : 0;
    rtv += (key == sfKeyLeft) ? 1 : 0;
    rtv += (key == sfKeyRight) ? 1 : 0;
    rtv += (key == sfKeyEscape) ? 1 : 0;
    return rtv;
}