/*
** EPITECH PROJECT, 2020
** script_monster
** File description:
** script player controller
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"

typedef struct data {
    sfVector2f *pos;
    dg_animator_t *animator;
} data_t;

void *scp_player_controller_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    dg_entity_t *entity = idata[0];
    dg_component_t *pos = dg_cpt_pos(0, 0);

    data->pos = pos->data;
    data->animator = idata[1];
    dg_entity_add_component(entity, pos);
    return data;
}

void scp_player_controller_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;
    sfVector2f move = {0, 0};

    move.x += (keymap_is_pressed(w, "right")) ? 1 : 0;
    move.x += (keymap_is_pressed(w, "left")) ? -1 : 0;
    move.y += (keymap_is_pressed(w, "down")) ? 1 : 0;
    move.y += (keymap_is_pressed(w, "up")) ? -1 : 0;
    (move.x > 0) ? dg_animator_set_animation(data->animator, "right") : NULL;
    (move.x < 0) ? dg_animator_set_animation(data->animator, "left") : NULL;
    (move.y < 0) ? dg_animator_set_animation(data->animator, "up") : NULL;
    (move.y > 0) ? dg_animator_set_animation(data->animator, "down") : NULL;
    data->pos->x += move.x * dt.microseconds / 10000;
    data->pos->y += move.y * dt.microseconds / 10000;
}

void scp_player_controller_end(void *data)
{
    data_t *d = (data_t *)data;

    free(d);
}