/*
** EPITECH PROJECT, 2020
** sys_escape
** File description:
** sys_escape
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "epitech_tools.h"

static void input_player(dg_animator_t *animator, sfVector2f *pos,
    dg_window_t *w, dg_entity_t *entity)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        pos->y += 1;
        dg_animator_set_animation(animator, "down");
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        pos->y -= 1;
        dg_animator_set_animation(animator, "up");
    }
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        dg_entity_free_component(entity, "sprite");
    }
}

void sys_player_control(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_animator_t *animator = (dg_animator_t *)
        (dg_entity_get_component(entity, "animator"));
    sfVector2f *pos = (sfVector2f *)(dg_entity_get_component(entity, "pos"));

    if (!dg_system_require(entity, 2, "animator", "pos")
        || dg_strcmp(entity->name, "player"))
        return;
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        pos->x += 1;
        dg_animator_set_animation(animator, "right");
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        pos->x -= 1;
        dg_animator_set_animation(animator, "left");
    }
    input_player(animator, pos, w, entity);
}