/*
** EPITECH PROJECT, 2020
** ent_map
** File description:
** ent_map
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"

static int **create_hud_progress_bar(int size)
{
    int **pb = malloc(sizeof(int *) * 2);

    pb[0] = malloc(sizeof(int) * (size + 1));
    for (int i = 0; i < size; i++)
        pb[0][i] = 224;
    pb[0][0] = 223;
    pb[0][size - 1] = 225;
    pb[0][size] = -1;
    pb[1] = NULL;
    return pb;
}

dg_entity_t *ent_hud_progress_bar(sfVector2f pos, int size,
    sfVector2f *data, sfColor color)
{
    dg_entity_t *entity = dg_entity_create("hud_box");
    int **map = create_hud_progress_bar(size);
    void *idata[5] = {entity, &pos, &size, data, &color};

    dg_entity_add_component(entity, dg_cpt_pos(pos.x, pos.y));
    dg_entity_add_component(entity, cpt_scale(3, 3));
    dg_entity_add_component(entity, cpt_tilemap(map,
        dg_ressources_get_spritesheet_by_name("hud"), 1));
    dg_entity_add_component(entity, cpt_script(&scp_hud_progress_bar_init,
        &scp_hud_progress_bar_loop, &scp_hud_save_end, idata));
    return entity;
}