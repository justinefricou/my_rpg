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

static button_t *create_select_box(general_data_t *gd)
{
    int i = 0;
    for (; gd->skills[i].name != NULL; i++);
    button_t *button_list = malloc(sizeof(button_t) * (i + 1));

    for (i = 0; gd->skills[i].name != NULL; i++)
        button_list[i] = (button_t){gd->skills[i].name, &skill_attack, &i};
    button_list[i] = (button_t){NULL, NULL, NULL};
    return button_list;
}

void *scp_hud_fight_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    dg_scene_t *scene = idata[1];
    dg_entity_t *entity = idata[0];
    general_data_t *gd = idata[3];
    button_t *button_list = create_select_box(gd);

    inventory_set_data(data, entity);
    data->previous = idata[2];
    data->side_box = ent_hud_box(50, 800, 5, 3);
    data->skill_box = ent_hud_menu_selector((sfVector2f){350, 20},
        button_list, scene, 1);
    data->launch_action = 0;
    dg_scene_add_ent(scene, data->side_box);
    dg_scene_add_ent(scene, data->skill_box);
    return data;
}

static void inventory_menu_active(dg_window_t *w, data_t *data,
    dg_entity_t *entity)
{
    general_data_t *gd = w->general_data;

    inventory_manage_move(w, data);
    if (keymap_is_clicked(w, "cancel", 1)) {
        sound_play(data->sound_activate);
        entity->destroy = 1;
    }
    if (keymap_is_clicked(w, "action", 0) && gd->inventory.len > 0) {
        data->is_active = 0;
        data->launch_action = 1;
    }
}

void scp_hud_fight_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;
    general_data_t *gd = w->general_data;

    if (data->is_active)
        inventory_menu_active(w, data, entity);
    else
        inventory_action(data, gd);
    inventory_update_selector(data, gd);
    inventory_update_weight(data, gd);
}

void scp_hud_fight_end(void *data)
{
    data_t *d = (data_t *)data;

    dg_scene_manager_remove("slots");
    *(d->previous) = 1;
    d->side_box->destroy = 1;
    d->skill_box->destroy = 1;
    free(d);
}