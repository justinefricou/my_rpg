/*
** EPITECH PROJECT, 2020
** background_menu
** File description:
** background_menu
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

static dg_animator_t *set_player_animator(void)
{
    dg_spritesheet_t *ss = dg_ressources_get_spritesheet(4);
    dg_animator_t *animator = dg_animator_create();
    dg_animation_t *anim = 0;
    char *name_list[4] = {"down", "right", "up", "left"};

    for (int i = 0; i < 4; i++) {
        anim = dg_animation_create(ss, 10);
        for (int j = 0; j < 4; j++)
            dg_animation_add(anim, (i * 4) + j);
        dg_animator_add(animator, name_list[i], anim);
    }
    return animator;
}

dg_entity_t *entity_player_create(void)
{
    dg_entity_t *player = dg_entity_create("player");

    dg_entity_add_component(player, dg_cpt_animator(&set_player_animator));
    dg_entity_add_component(player, dg_cpt_pos(0, 0));
    return player;
}