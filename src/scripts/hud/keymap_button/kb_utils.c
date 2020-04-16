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