/*
** EPITECH PROJECT, 2020
** rpg
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

void *scp_event_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    dg_entity_t *entity = idata[0];
    dg_component_t *pos = dg_cpt_pos(1000, 500);
    dg_scene_t *scene = idata[2];
    dg_entity_t *map_ent = dg_get_entity(scene->entities, "map");

    data->pos = pos->data;
    data->collide = dg_entity_get_component(map_ent, "tilecollide");
    data->animator = idata[1];
    data->speed = 2;
    dg_entity_add_component(entity, pos);
    return data;
}

static void collide(sfVector2f *move, data_t *data)
{
    sfVector2f pos = {(data->pos->x),
        data->pos->y};
    sfVector2i tiled_posx[2] = {
        {(data->pos->x + move->x) / (16 * 3),
        data->pos->y / (16 * 3)},
        {(data->pos->x + move->x + (16 * 3 / 2)) / (16 * 3),
        (data->pos->y + (16 * 3 / 2)) / (16 * 3)}};
    sfVector2i tiled_posy[2] = {{(data->pos->x) / (16 * 3),
        (data->pos->y + move->y) / (16 * 3)},
        {(data->pos->x + (16 * 3 / 2)) / (16 * 3),
        (data->pos->y + move->y + (16 * 3 / 2)) / (16 * 3)}};

    if (data->collide->map[tiled_posx[0].y][tiled_posx[0].x] ||
        data->collide->map[tiled_posx[1].y][tiled_posx[1].x])
        move->x = 0;
    if (data->collide->map[tiled_posy[0].y][tiled_posy[0].x] ||
        data->collide->map[tiled_posy[1].y][tiled_posy[1].x])
        move->y = 0;
}

void scp_player_event_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;
    sfVector2f move = {0, 0};

    move.x += (keymap_is_pressed(w, "right")) ? 1 : 0;
    move.x += (keymap_is_pressed(w, "left")) ? -1 : 0;
    move.y += (keymap_is_pressed(w, "down")) ? 1 : 0;
    move.y += (keymap_is_pressed(w, "up")) ? -1 : 0;
    move.x *= dt.microseconds / 10000 * data->speed * 1.5;
    move.y *= dt.microseconds / 10000 * data->speed * 1.5;
    collide(&move, data);
    (move.x > 0) ? dg_animator_set_animation(data->animator, "right") : NULL;
    (move.x < 0) ? dg_animator_set_animation(data->animator, "left") : NULL;
    (move.y < 0) ? dg_animator_set_animation(data->animator, "up") : NULL;
    (move.y > 0) ? dg_animator_set_animation(data->animator, "down") : NULL;
    data->pos->x += move.x;
    data->pos->y += move.y;
}

void scp_event_end(void *data)
{
    data_t *d = (data_t *)data;

    free(d);
}