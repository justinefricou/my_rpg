/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** draw rectangle shapes
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

static void render_shape(sfRectangleShape *shape,
    sfVector2f *pos, sfVector2f *scale)
{
    sfVector2f oscale = sfRectangleShape_getScale(shape);
    sfVector2f opos = sfRectangleShape_getPosition(shape);
    sfVector2f nscale = (sfVector2f) {oscale.x * scale->x,
        oscale.y * scale->y};
    sfVector2f npos = (sfVector2f) {opos.x + pos->x,
        opos.y + pos->y};

    if (scale)
        sfRectangleShape_setScale(shape, nscale);
    sfRectangleShape_setPosition(shape, npos);
}

static void render_shape_back(sfRectangleShape *shape,
    sfVector2f *pos, sfVector2f *scale)
{
    sfVector2f oscale = sfRectangleShape_getScale(shape);
    sfVector2f opos = sfRectangleShape_getPosition(shape);
    sfVector2f nscale = (sfVector2f) {oscale.x / scale->x,
        oscale.y / scale->y};
    sfVector2f npos = (sfVector2f) {opos.x - pos->x,
        opos.y - pos->y};

    if (scale)
        sfRectangleShape_setScale(shape, nscale);
    sfRectangleShape_setPosition(shape, npos);
}

void sys_shape_rectangle(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_entity_t *camera = dg_get_entity(*entities, "camera");
    sfVector2f *c_pos = (sfVector2f *)(dg_entity_get_component(camera, "pos"));
    sfRectangleShape *shape = (sfRectangleShape *)
        (dg_entity_get_component(entity, "shape_rectangle"));
    sfVector2f *pos = (sfVector2f *)
        (dg_entity_get_component(entity, "pos"));
    sfVector2f *scale = (sfVector2f *)
        (dg_entity_get_component(entity, "scale"));

    if (!dg_system_require(entity, 2, "shape_rectangle", "pos") || !camera)
        return;
    render_shape(shape, pos, scale);
    sfRenderWindow_drawRectangleShape(w->window, shape, NULL);
    render_shape_back(shape, pos, scale);
}