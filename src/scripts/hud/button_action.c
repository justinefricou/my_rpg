/*
** EPITECH PROJECT, 2020
** script_monster
** File description:
** script player controller
*/

#include "libdragon.h"
#include "ecs.h"

int action_quit(int *previous, void *data, dg_window_t *w)
{
    w->quit = 1;
}

void action_options(int *previous, void *data, dg_window_t *w)
{
    char *scene_name = (char *)data;
    dg_scene_t *scene = dg_scene_manager_get_scene(scene_name);

    *previous = 0;
    dg_scene_add_ent(scene, ent_hud_options(previous, scene));
}