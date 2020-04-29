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

static void inventory_create_ent(data_t *data, int i)
{
    sfVector2f slot = {i % 4, i / 4};
    data->slots.slots[i].quantity.entity = ent_text(
        500 + slot.x * 385, 110 + 160 * slot.y, 30, "");
    data->slots.slots[i].name.entity = ent_text(
        500 + slot.x * 385, 45 + 160 * slot.y, 25, "");
    data->slots.slots[i].icon.entity = ent_sprite(
        dg_ressources_get_spritesheet_by_name("icons"),
        0, 3.5, (sfVector2f){375 + slot.x * 385, 44 + 160 * slot.y});
    inventory_active_slot(data, i, 0);
}

static void inventory_set_slots(data_t *data)
{
    data->slots.layer = scene_tmp_hover("slots");
    for (int i = 0; i < NB_SLOT; i++) {
        inventory_create_ent(data, i);
        data->slots.slots[i].quantity.text = dg_entity_get_component(
        data->slots.slots[i].quantity.entity, "text");
        data->slots.slots[i].name.text = dg_entity_get_component(
        data->slots.slots[i].name.entity, "text");
        data->slots.slots[i].icon.id = dg_entity_get_component(
            data->slots.slots[i].icon.entity, "sprite");
        dg_scene_add_ent(data->slots.layer,
            data->slots.slots[i].quantity.entity);
        dg_scene_add_ent(data->slots.layer,
            data->slots.slots[i].name.entity);
        dg_scene_add_ent(data->slots.layer,
            data->slots.slots[i].icon.entity);
    }
}

void inventory_set_data(data_t *data, dg_entity_t *entity)
{
    dg_component_t *pos = dg_cpt_pos(350, 20);
    dg_component_t *selector = cpt_shape_rectangle((sfVector2f){0, 0},
        (sfVector2f){32 * 3 * 16 / 4, 20 * 3 * 16 / 3},
        (sfColor){255, 255, 255, 100},
        (sfColor){0, 0, 0, 0});
    dg_entity_t *weight_ent = ent_text(70, 880, 35, "  0 / 0");

    dg_entity_add_component(entity, pos);
    dg_entity_add_component(entity, selector);
    data->selector.select = 0;
    data->selector.selector = selector->data;
    data->selector.defilement = 0;
    data->is_active = 1;
    data->weight = dg_entity_get_component(weight_ent, "text");
    inventory_set_slots(data);
    dg_scene_manager_add_scene(data->slots.layer);
    inventory_set_sounds(data);
    dg_scene_add_ent(data->slots.layer,
            ent_text(100, 810, 35, "Weight:"));
    dg_scene_add_ent(data->slots.layer, weight_ent);
}