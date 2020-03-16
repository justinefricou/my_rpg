/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** script system
*/

#include <stdlib.h>
#include "libdragon.h"
#include "script.h"
#include "ecs.h"

void sys_script(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *) dg_entity_get_component(entity, "script");

    if (!script)
        return;
    script->loop(entity, w, entities, dt);
}