/*
** EPITECH PROJECT, 2020
** sys_interact_dialogue
** File description:
** sys_interact_dialogue
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

void sys_interact_dialogue(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_scene_t *game_scene = dg_scene_manager_get_scene("layer_event");

    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
    }
}