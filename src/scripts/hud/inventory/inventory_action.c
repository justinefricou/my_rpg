/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** script player controller
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "hud/hud_inventory.h"
#include "general_data.h"

static button_t *create_inv_action_box(data_t *data)
{
    button_t *button_list = malloc(sizeof(button_t) * 4);
    
    button_list[0] = (button_t){"Use", &inv_use, data};
    button_list[1] = (button_t){"Throw", &inv_throw, data};
    button_list[2] = (button_t){"Cancel", &inv_cancel, data};
    button_list[3] = (button_t){NULL, NULL, NULL};
    return button_list;
}

void lauch_inv_action(data_t *data, general_data_t *gd)
{
    button_t *button_list = create_inv_action_box(data);

    data->inv_action = scene_tmp_hover_ws("inv_action");
    dg_scene_add_ent(data->inv_action, ent_hud_cancel_menu_selector(
        (sfVector2f){1650, 680}, button_list,
        data->inv_action, button_list[2]));
    dg_scene_add_ent(data->inv_action, ent_text(360, 810, 30,
        gd->object_list.object[gd->inventory.slot[
        data->selector.select].id].description));
    dg_scene_add_ent(data->inv_action, ent_hud_box(350, 800, 32, 4));
    dg_scene_manager_add_scene(data->inv_action);
}

void inventory_action(data_t *data, general_data_t *gd)
{
    if (data->launch_action == 1) {
        lauch_inv_action(data, gd);
        data->launch_action = 0;
    } else if (data->launch_action == 2) {
        dg_scene_manager_remove("inv_action");
        data->launch_action = 0;
        data->is_active = 1;
    } else {

    }
}