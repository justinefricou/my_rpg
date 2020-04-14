/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** main
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "general_data.h"

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
    return dg_play((sfVector2u){1920, 1080}, "Defender", 0, NULL);
}
