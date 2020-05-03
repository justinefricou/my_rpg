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
#include "save_load.h"

void *dg_init(dg_window_t *window, void *import)
{
    general_data_t *gd = NULL;

    dg_scene_manager_create();
    init_img();
    init_audio();
    window->general_data = create_general_data();
    gd = window->general_data;
    load_saved_options(&(gd->options));
    dg_scene_manager_add_scene(scene_intro());
    return 0;
}

int dg_loop(dg_window_t *w, void *var, sfTime dt)
{
    sfRenderWindow_clear(w->window, sfBlack);
    update_inventory(w->general_data);
    update_level(w->general_data);
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
    int *ran = malloc(sizeof(int));
    srand(ran);
    free(ran);
    return dg_play((sfVector2u){1920, 1080}, "Murder at High Noon", 0, NULL);
}
