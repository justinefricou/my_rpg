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
#include "tilemap.h"

typedef struct data {
    sfVector2f *pos;
    dg_animator_t *animator;
    tilemap_t *collide;
    int speed;
} data_t;

void *scp_player_controller_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    dg_entity_t *entity = idata[0];
    dg_component_t *pos = dg_cpt_pos(88 * 16 * 3, 9 * 16 * 3);
    dg_scene_t *scene = idata[2];
    dg_entity_t *map_ent = dg_get_entity(scene->entities, "map");

    data->pos = pos->data;
    data->collide = dg_entity_get_component(map_ent, "tilecollide");
    data->animator = idata[1];
    data->speed = 2;
    dg_entity_add_component(entity, pos);
    return data;
}

//16 * 3 = 48
int try_collide(data_t *data, sfVector2f m)
{
    sfVector2f p = {(data->pos->x), data->pos->y};
    sfVector2f tiled_pos[4] = {
        {(p.x + m.x) / (48), (p.y + m.y) / (48)},
        {(p.x + m.x + 24) / 48, (p.y + m.y + 24) / (48)},
        {(p.x + m.x) / 48, (p.y + m.y + 24) / (48)},
        {(p.x + m.x + 24) / 48, (p.y + m.y) / (48)}
    };

    for ( int i = 0; i < 4; i++) {
        if (tiled_pos[i].y <= 0 || tiled_pos[i].x <= 0.3 ||
            tiled_pos[i].x + 0.3 >= data->collide->width ||
            tiled_pos[i].y + 0.3 >= data->collide->height)
            return 1;
        if (data->collide->map[(int)tiled_pos[i].y][(int)tiled_pos[i].x])
            return 1;
    }
    return 0;
}

static void collide(sfVector2f *move, data_t *data)
{
    if (try_collide(data, (sfVector2f){move->x, 0}))
        move->x = 0;
    if (try_collide(data, (sfVector2f){0, move->y}))
        move->y = 0;
}

void scp_player_controller_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    general_data_t *gd = w->general_data;
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;
    sfVector2f move = {0, 0};

    if (!gd->lock.move) {
        move.x += (keymap_is_pressed(w, "right")) ? 1 : 0;
        move.x += (keymap_is_pressed(w, "left")) ? -1 : 0;
        move.y += (keymap_is_pressed(w, "down")) ? 1 : 0;
        move.y += (keymap_is_pressed(w, "up")) ? -1 : 0;
    }
    move.x *= dt.microseconds / 10000.0 * data->speed * 1.5;
    move.y *= dt.microseconds / 10000.0 * data->speed * 1.5;
    collide(&move, data);
    (move.x > 0) ? dg_animator_set_animation(data->animator, "right") : NULL;
    (move.x < 0) ? dg_animator_set_animation(data->animator, "left") : NULL;
    (move.y < 0) ? dg_animator_set_animation(data->animator, "up") : NULL;
    (move.y > 0) ? dg_animator_set_animation(data->animator, "down") : NULL;
    data->pos->x += move.x;
    data->pos->y += move.y;
}

void scp_player_controller_end(void *data)
{
    data_t *d = (data_t *)data;

    free(d);
}