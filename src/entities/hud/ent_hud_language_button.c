/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** keymap buttons
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"

static int **create_hud_lang_button(int size)
{
    int **pb = malloc(sizeof(int *) * 2);

    pb[0] = malloc(sizeof(int) * (size + 1));
    for (int i = 0; i < size; i++)
        pb[0][i] = 140;
    pb[0][0] = 139;
    pb[0][size - 1] = 141;
    pb[0][size] = -1;
    pb[1] = NULL;
    return pb;
}

dg_entity_t *ent_hud_language_button(sfVector2f pos, int size, dg_scene_t *scene)
{
    int tmp = 0;
    dg_entity_t *entity = dg_entity_create("hud_box");
    int **map = create_hud_lang_button(size);
    void *idata[5] = {entity, &pos, &size, &tmp, scene};

    dg_entity_add_component(entity, dg_cpt_pos(pos.x, pos.y));
    dg_entity_add_component(entity, cpt_scale(3, 3));
    dg_entity_add_component(entity, cpt_tilemap(map,
        dg_ressources_get_spritesheet_by_name("hud"), 1));
    dg_entity_add_component(entity, cpt_script(&scp_hud_language_button_init,
        &scp_hud_language_button_loop, &scp_hud_language_button_end, idata));
    return entity;
}