/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "general_data.h"

void fix_empty_slot(general_data_t *gd, int hole)
{
    for (; hole + 1 < gd->inventory.len; hole++) {
        gd->inventory.slot[hole].id = gd->inventory.slot[hole + 1].id;
        gd->inventory.slot[hole].nb = gd->inventory.slot[hole + 1].nb;
    }
    gd->inventory.slot[hole].id = -1;
    gd->inventory.slot[hole].nb = 0;
    gd->inventory.len--;
}

void update_inventory(general_data_t *gd)
{
    int *id = 0;
    int *nb = 0; 

    for (int i = 0; i < gd->inventory.len; i++) {
        id = &(gd->inventory.slot[i].id);
        nb = &(gd->inventory.slot[i].nb);
        *id = (*nb == 0) ? -1 : *id;
        if (*id == -1)
            fix_empty_slot(gd, i);
    }
}

void *dg_init(dg_window_t *window, void *import)
{
    dg_scene_manager_create();
    init_img();
    init_audio();
    window->general_data = create_general_data();
    dg_scene_manager_add_scene(scene_main_menu());
    dg_scene_manager_add_scene(scene_main_menu_hover());
    return 0;
}

int dg_loop(dg_window_t *w, void *var, sfTime dt)
{
    sfRenderWindow_clear(w->window, sfRed);
    update_inventory(w->general_data);
    dg_scene_manager_update(w, dt);
    set_volume(w);
    return 0;
}

void dg_end(void *var, int id)
{
    dg_scene_manager_destroy();
    dg_ressources_destroy();
}

int main(int argc, char **argv)
{
    return dg_play((sfVector2u){1920, 1080}, "RPG", 0, NULL);
}
