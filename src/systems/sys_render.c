/*
** EPITECH PROJECT, 2020
** dg_cpt_spritesheet
** File description:
** dg_cpt_spritesheet
*/

#include <stdlib.h>
#include "dg_component.h"
#include "ecs.h"

static sfSprite *render_sprite(sfVector2f *scale, dg_spritesheet_t *sheet,
    sfVector2f *pos, sfColor *color)
{
    sfSprite *sprite = sfSprite_create();

    if (scale)
        sfSprite_setScale(sprite, *scale);
    sfSprite_setPosition(sprite, *pos);
    if (color)
        sfSprite_setColor(sprite, *color);
    dg_spritesheet_to_sprite(sheet, sprite, 0);
    return sprite;
}

void sys_render(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_entity_t *camera = dg_get_entity(*entities, "camera");
    sfVector2f *c_pos = (sfVector2f *)(dg_entity_get_component(camera, "pos"));
    dg_spritesheet_t *sheet = (dg_spritesheet_t *)
        (dg_entity_get_component(entity, "spritesheet"));
    sfColor *color = (sfColor *)
        (dg_entity_get_component(entity, "color"));
    sfVector2f *pos = (sfVector2f *)
        (dg_entity_get_component(entity, "pos"));
    sfVector2f *scale = (sfVector2f *)
        (dg_entity_get_component(entity, "scale"));
    sfSprite *sprite = 0;

    if (!dg_system_require(entity, 2, "spritesheet", "pos") || !camera)
        return;
    sprite = render_sprite(scale, sheet, pos, color);
    dg_camera_render(*c_pos, sprite, w);
    sfSprite_destroy(sprite);
}