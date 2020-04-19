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
#include "hud/hud_inventory.h"

void *scp_hud_inventory_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    dg_scene_t *scene = idata[1];
    dg_entity_t *entity = idata[0];

    inventory_set_data(data, entity);
    data->previous = idata[2];
    data->hud_box = ent_hud_box(350, 20, 32, 20);
    dg_scene_add_ent(scene, data->hud_box);
    return data;
}

static void inventory_menu_active(dg_window_t *w, data_t *data)
{
    inventory_manage_move(w, data);
}

void scp_hud_inventory_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;
    general_data_t *gd = w->general_data;

    if (data->is_active)
        inventory_menu_active(w, data);
    inventory_update_selector(data, gd);
    if (keymap_is_clicked(w, "cancel", 1)) {
        sound_play(data->sound_activate);
        entity->destroy = 1;
    }
}

void scp_hud_inventory_end(void *data)
{
    data_t *d = (data_t *)data;

    *(d->previous) = 1;
    d->hud_box->destroy = 1;
    //free(d->button_list);
    //free(d->buttons);
    free(d);
}