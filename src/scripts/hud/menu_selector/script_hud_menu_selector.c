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
#include "hud_menu_selector.h"

static void hud_selector_set_sounds(data_t *data)
{

}

static data_t *set_data(dg_component_t *pos,
    button_t *button_list, dg_scene_t *scene, int has_box)
{
    data_t *data = malloc(sizeof(data_t));

    data->select = 0;
    data->is_active = 1;
    data->llen = 0;
    data->pos = pos->data;
    data->pos_memory = *(data->pos);
    if (!button_list)
        return data;
    for (data->llen = 0; button_list[data->llen].name; data->llen++);
    if (has_box)
        data->hud_box = ent_hud_box(data->pos->x, data->pos->y,
            get_longest_name(button_list, data->llen) / 1.5, data->llen);
    else
        data->hud_box = NULL;
    data->buttons = create_buttons(*(data->pos), scene, button_list,
        data->llen);
    data->action = create_actions(button_list, data->llen);
    hud_selector_set_sounds(data);
    return data;
}

void *scp_hud_menu_selector_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = 0;
    dg_scene_t *scene = idata[3];
    button_t *button_list = idata[2];
    dg_entity_t *entity = idata[0];
    sfVector2f *dpos = idata[1];
    dg_component_t *pos = dg_cpt_pos(dpos->x, dpos->y);
    dg_component_t *selector = 0;

    dg_entity_add_component(entity, pos);
    data = set_data(pos, button_list, scene, *((int *)idata[4]));
    selector = cpt_shape_rectangle((sfVector2f){0, 0},
        (sfVector2f){get_longest_name(button_list, data->llen) / 1.5 * 16 - 4
        , 14}, (sfColor){255, 255, 255, 100},
        (sfColor){0, 0, 0, 0});
    if (*((int *)idata[4]))
        dg_scene_add_ent(scene, data->hud_box);
    dg_entity_add_component(entity, selector);
    data->selector = selector->data;
    return data;
}

void hud_menu_active(dg_window_t *w, data_t *data)
{
    if (w->events.keyboard_pressed_down && data->select < data->llen - 1)
            data->select++;
    if (w->events.keyboard_pressed_up && data->select > 0)
        data->select--;
    if (w->events.keyboard_pressed_enter || w->events.keyboard_pressed_space) {
        data->action[data->select](w);
    }
}

void scp_hud_menu_selector_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;

    sfRectangleShape_setPosition(data->selector,
        (sfVector2f){2 * 3, 2.5 * 3 + data->select * 45});
    if (data->is_active)
        hud_menu_active(w, data);
    update_position(data);
}

void scp_hud_menu_selector_end(void *data)
{
    data_t *d = (data_t *)data;

    free(d->action);
    free(d->buttons);
    free(d);
}