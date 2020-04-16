/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** hud : cancel menu selector
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "hud/hud.h"

dg_entity_t *ent_hud_cancel_menu_selector(sfVector2f pos,
    button_t *button_list, dg_scene_t *scene, button_t action)
{
    int has_box = 1;
    dg_entity_t *entity = dg_entity_create("hud_menu_selector");
    void *idata[6] = {entity, &pos, button_list, scene, &has_box, &action};

    dg_entity_add_component(entity, dg_cpt_pos(pos.x, pos.y));
    dg_entity_add_component(entity, cpt_script(&scp_hud_menu_selector_init,
        &scp_hud_menu_selector_loop, &scp_hud_menu_selector_end, idata));
    return entity;
}