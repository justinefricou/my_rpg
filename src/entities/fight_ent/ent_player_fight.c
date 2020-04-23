/*
** EPITECH PROJECT, 2020
** ent_player_fight
** File description:
** ent_player_fight
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"

static dg_animator_t *set_player_animator(void)
{
    dg_spritesheet_t *ss = dg_ressources_get_spritesheet_by_name("enemy_1");
    dg_animator_t *animator = dg_animator_create();
    dg_animation_t *anim = 0;

    anim = dg_animation_create(ss, 4);
    dg_animation_add(anim, 0);
    dg_animation_add(anim, 1);
    dg_animation_add(anim, 2);
    dg_animator_add(animator, "idle", anim);
    return animator;
}

dg_entity_t *entity_player_fight_create(void)
{
    dg_entity_t *player = dg_entity_create("player_fight");
    dg_component_t *animator = dg_cpt_animator(&set_player_animator);
    void *idata[2] = {player, animator->data};

    dg_entity_add_component(player, animator);
    dg_entity_add_component(player, dg_cpt_pos(500, 750));
    return player;
}