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

static void inventory_set_sounds(data_t *data)
{
    data->sound_activate = dg_ressources_get_audio_by_name("hud_activate");
    data->sound_move = dg_ressources_get_audio_by_name("hud_move");
}

void inventory_set_data(data_t *data, dg_entity_t *entity)
{
    dg_component_t *pos = dg_cpt_pos(350, 20);
    dg_component_t *selector = cpt_shape_rectangle((sfVector2f){0, 0},
        (sfVector2f){32 * 3 * 16 / 4, 20 * 3 * 16 / 3},
        (sfColor){255, 255, 255, 100},
        (sfColor){0, 0, 0, 0});
    
    dg_entity_add_component(entity, pos);
    dg_entity_add_component(entity, selector);
    data->selector.select = 0;
    data->selector.selector = selector->data;
    data->selector.defilement = 0;
    data->is_active = 1;
    inventory_set_sounds(data);
}