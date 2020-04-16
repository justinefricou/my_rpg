/*
** EPITECH PROJECT, 2020
** dg_cpt_spritesheet
** File description:
** dg_cpt_spritesheet
*/

#include <stdlib.h>
#include "dragon/dg_component.h"
#include "ecs.h"
#include "tilemap.h"
#include "transform.h"

static sfSprite *tm_sys_set_sprite(sfColor *color, transform_t transform)
{
    sfSprite *sprite = sfSprite_create();

    if (color)
        sfSprite_setColor(sprite, *color);
    sfSprite_setScale(sprite, transform.scale);
    return sprite;
}

static void tilemap_sys_draw(tilemap_t *tm, transform_t transform,
    sfColor *color, dg_window_t *w)
{
    sfSprite *sprite = tm_sys_set_sprite(color, transform);
    sfVector2f new_pos = transform.pos;

    if (!tm)
        return;
    for (int y = 0; y < tm->height; y++) {
        new_pos.x = transform.pos.x;
        for (int x = 0; x < tm->width; x++) {
            sfSprite_setPosition(sprite, new_pos);
            (tm->map[y][x] > 0) ?
                dg_spritesheet_to_sprite(tm->sheet, sprite,
                    tm->map[y][x] - 1) : NULL;
            dg_camera_render((sfVector2f){0, 0}, sprite,  w);
            new_pos.x += tm->sheet->x * transform.scale.x;
        }
        new_pos.y += tm->sheet->y * transform.scale.y;
    }
    sfSprite_destroy(sprite);
}

void sys_tm_render(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_entity_t *camera = dg_get_entity(*entities, "camera");
    sfVector2f *c_pos = (sfVector2f *)(dg_entity_get_component(camera, "pos"));
    tilemap_t *tm = (tilemap_t *)
        (dg_entity_get_component(entity, "tilemap"));
    sfVector2f *pos = (sfVector2f *)
        (dg_entity_get_component(entity, "pos"));
    sfVector2f *scale = (sfVector2f *)
        (dg_entity_get_component(entity, "scale"));
    sfColor *color = (sfColor *)
        (dg_entity_get_component(entity, "color"));
    sfVector2f new_pos = {0};

    if (!tm || !pos || !camera)
        return;
    new_pos = (sfVector2f){pos->x - c_pos->x, pos->y - c_pos->y};
    tilemap_sys_draw(tm, transformm(new_pos, *scale), color, w);
}