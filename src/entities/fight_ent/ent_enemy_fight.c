/*
** EPITECH PROJECT, 2020
** ent_enemy_fight
** File description:
** ent_enemy_fight
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"

static dg_animator_t *set_enemy_animator(void)
{
    dg_spritesheet_t *ss = dg_ressources_get_spritesheet_by_name("enemy_2");
    dg_animator_t *animator = dg_animator_create();
    dg_animation_t *anim = 0;

    anim = dg_animation_create(ss, 4);
    dg_animation_add(anim, 0);
    dg_animation_add(anim, 1);
    dg_animation_add(anim, 2);
    dg_animator_add(animator, "idle", anim);
    return animator;
}

dg_entity_t *entity_enemy_fight_create(void)
{
    dg_entity_t *enemy = dg_entity_create("enemy_fight");
    dg_component_t *animator = dg_cpt_animator(&set_enemy_animator);
    void *idata[2] = {enemy, animator->data};

    dg_entity_add_component(enemy, animator);
    dg_entity_add_component(enemy, dg_cpt_pos(1250, 350));
    dg_entity_add_component(enemy, cpt_scale(4, 4));
    return enemy;
}