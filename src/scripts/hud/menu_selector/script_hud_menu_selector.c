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
#include "hud/hud_menu_selector.h"
#include "general_data.h"

void *scp_hud_menu_selector_init(void *init_data)
{
    void **idata = (void **) init_data;
    dg_scene_t *scene = idata[3];
    button_t *button_list = idata[2];
    button_t *cancel = idata[5];
    dg_entity_t *entity = idata[0];
    sfVector2f *dpos = idata[1];
    dg_component_t *pos = dg_cpt_pos(dpos->x, dpos->y);
    data_t *data = menu_selector_set_data(pos, button_list, scene,
        *((int *)idata[4]));
    dg_component_t *selector = cpt_shape_rectangle((sfVector2f){0, 0},
        menu_selector_set_rect(data), (sfColor){255, 255, 255, 100},
        sfTransparent);

    dg_entity_add_component(entity, pos);
    (*((int *)idata[4])) ? dg_scene_add_ent(scene, data->hud_box) : 0;
    dg_entity_add_component(entity, selector);
    data->selector = selector->data;
    data->cancel.action = (cancel) ? cancel->action : NULL;
    data->cancel.data = (cancel) ? cancel->data : NULL;
    return data;
}

static void hud_menu_actions(dg_window_t *w, data_t *data)
{
    if (keymap_is_clicked(w, "action", 1)) {
        sound_play(data->sound_activate);
        data->button_list[data->select].action
            (&(data->is_active), data->button_list[data->select].data, w);
    }
    if (keymap_is_clicked(w, "cancel", 1) && data->cancel.action != NULL) {
        sound_play(data->sound_activate);
        data->cancel.action(&(data->is_active), data->cancel.data, w);
    }
}

void hud_menu_active(dg_window_t *w, data_t *data)
{
    if (keymap_is_clicked(w, "down", 0) && data->select < data->llen - 1) {
        sound_play(data->sound_move);
        data->select++;
    }
    if (keymap_is_clicked(w, "up", 0) && data->select > 0) {
        sound_play(data->sound_move);
        data->select--;
    }
    hud_options_manage_mouse(w, data);
    hud_menu_actions(w, data);
}

void scp_hud_menu_selector_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;

    sfRectangleShape_setPosition(data->selector,
        (sfVector2f){2 * 3, 2 + data->select * (16 * 3)});
    if (data->is_active)
        hud_menu_active(w, data);
    update_position(data);
}

void scp_hud_menu_selector_end(void *data)
{
    data_t *d = (data_t *)data;

    d->hud_box->destroy = 1;
    for (int i = 0; i < d->llen; i++)
        d->buttons[i]->destroy = 1;
    free(d->button_list);
    free(d->buttons);
    free(d);
}