/*
** EPITECH PROJECT, 2020
** sys_button
** File description:
** sys_button
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

void set_color(sfColor *color, sfIntRect *rect,
    sfVector2i mouse, dg_window_t *w)
{
    *color = (sfColor){255, 255, 255, 255};

    if (sfIntRect_contains(rect, mouse.x, mouse.y)) {
        *color = (sfColor){200, 200, 200, 255};
        if (w->events.mouse_pressed_left)
            *color = (sfColor){0, 0, 0, 255};
    }
}

static void rect_pos(sfVector2f *pos, sfIntRect *rect)
{
    rect->left = pos->x;
    rect->top = pos->y;
}

void sys_button(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_entity_t *camera = dg_get_entity(*entities, "camera");
    sfVector2f *c_pos = (sfVector2f *)(dg_entity_get_component(camera, "pos"));
    void (*action)(dg_window_t *) = (void (*)(dg_window_t *))
        (dg_entity_get_component(entity, "action"));
    sfVector2f *pos = (sfVector2f *)
        (dg_entity_get_component(entity, "pos"));
    sfIntRect *rect = (sfIntRect *)
        (dg_entity_get_component(entity, "box_collider"));
    sfVector2i m = sfMouse_getPositionRenderWindow(w->window);
    sfColor *color = dg_entity_get_component(entity, "color");

    if (!dg_system_require(entity, 3, "box_collider", "pos", "action")
        || !camera)
        return;
    rect_pos(pos, rect);
    (color) ? set_color(color, rect, m, w) : 0;
    if (sfIntRect_contains(rect, m.x, m.y) && w->events.mouse_pressed_left) {
        action ? action(w) : 0;
        dg_entity_add_component(entity, cpt_sound("./sound/click.ogg"));
    }
}