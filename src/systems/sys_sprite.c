/*
** EPITECH PROJECT, 2020
** dg_cpt_spritesheet
** File description:
** dg_cpt_spritesheet
*/

#include <stdlib.h>
#include "dragon/dg_component.h"
#include "ecs.h"
#include "sprite.h"

sfSprite *sprite_render(sfVector2f *scale, sprite_t *sp,
    sfVector2f *pos, sfColor *color)
{
    sfSprite *sprite = sfSprite_create();

    if (scale)
        sfSprite_setScale(sprite, *scale);
    sfSprite_setPosition(sprite, *pos);
    if (color)
        sfSprite_setColor(sprite, *color);
    dg_spritesheet_to_sprite(sp->sheet, sprite, sp->id);
    return sprite;
}

void sys_sprite(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_entity_t *camera = dg_get_entity(*entities, "camera");
    sfVector2f *c_pos = (sfVector2f *)(dg_entity_get_component(camera, "pos"));
    sprite_t *sp = (sprite_t *)
        (dg_entity_get_component(entity, "sprite"));
    sfColor *color = (sfColor *)
        (dg_entity_get_component(entity, "color"));
    sfVector2f *pos = (sfVector2f *)
        (dg_entity_get_component(entity, "pos"));
    sfVector2f *scale = (sfVector2f *)
        (dg_entity_get_component(entity, "scale"));
    sfSprite *sprite = 0;
    float *rot = (float *) dg_entity_get_component(entity, "rot");

    if (!dg_system_require(entity, 2, "sprite", "pos") || !camera)
        return;
    sprite = sprite_render(scale, sp, pos, color);
    if (rot)
        sfSprite_setRotation(sprite, *rot);
    dg_camera_render(*c_pos, sprite, w);
    sfSprite_destroy(sprite);
}