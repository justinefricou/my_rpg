/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** draw circle shapes
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

static void render_shape(sfCircleShape *shape,
    sfVector2f *pos, sfVector2f *scale)
{
    sfVector2f oscale = sfCircleShape_getScale(shape);
    sfVector2f opos = sfCircleShape_getPosition(shape);
    sfVector2f nscale = (sfVector2f) {oscale.x * scale->x,
        oscale.y * scale->y};
    sfVector2f npos = (sfVector2f) {opos.x + pos->x,
        opos.y + pos->y};

    if (scale)
        sfCircleShape_setScale(shape, nscale);
    sfCircleShape_setPosition(shape, npos);
}

static void render_shape_back(sfCircleShape *shape,
    sfVector2f *pos, sfVector2f *scale)
{
    sfVector2f oscale = sfCircleShape_getScale(shape);
    sfVector2f opos = sfCircleShape_getPosition(shape);
    sfVector2f nscale = (sfVector2f) {oscale.x / scale->x,
        oscale.y / scale->y};
    sfVector2f npos = (sfVector2f) {opos.x - pos->x,
        opos.y - pos->y};

    if (scale)
        sfCircleShape_setScale(shape, nscale);
    sfCircleShape_setPosition(shape, npos);
}

void sys_shape_circle(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_entity_t *camera = dg_get_entity(*entities, "camera");
    sfVector2f *c_pos = (sfVector2f *)(dg_entity_get_component(camera, "pos"));
    sfCircleShape *shape = (sfCircleShape *)
        (dg_entity_get_component(entity, "shape_circle"));
    sfVector2f *pos = (sfVector2f *)
        (dg_entity_get_component(entity, "pos"));
    sfVector2f *scale = (sfVector2f *)
        (dg_entity_get_component(entity, "scale"));

    if (!dg_system_require(entity, 2, "shape_circle", "pos") || !camera)
        return;
    render_shape(shape, pos, scale);
    sfRenderWindow_drawCircleShape(w->window, shape, NULL);
    render_shape_back(shape, pos, scale);
}