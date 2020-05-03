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

static dg_animator_t *set_enemy_animator_bliblio(void)
{
    dg_spritesheet_t *ss = dg_ressources_get_spritesheet_by_name("enemy_1");
    dg_animator_t *animator = dg_animator_create();
    dg_animation_t *anim = 0;

    anim = dg_animation_create(ss, 3);
    dg_animation_add(anim, 0);
    dg_animation_add(anim, 1);
    dg_animation_add(anim, 2);
    dg_animator_add(animator, "idle", anim);
    return animator;
}

static dg_animator_t *set_enemy_animator_bucheron(void)
{
    dg_spritesheet_t *ss = dg_ressources_get_spritesheet_by_name("enemy_2");
    dg_animator_t *animator = dg_animator_create();
    dg_animation_t *anim = 0;

    anim = dg_animation_create(ss, 3);
    dg_animation_add(anim, 0);
    dg_animation_add(anim, 1);
    dg_animation_add(anim, 2);
    dg_animator_add(animator, "idle", anim);
    return animator;
}

static dg_animator_t *set_enemy_animator_pdg(void)
{
    dg_spritesheet_t *ss = dg_ressources_get_spritesheet_by_name("enemy_3");
    dg_animator_t *animator = dg_animator_create();
    dg_animation_t *anim = 0;

    anim = dg_animation_create(ss, 3);
    dg_animation_add(anim, 0);
    dg_animation_add(anim, 1);
    dg_animation_add(anim, 2);
    dg_animator_add(animator, "idle", anim);
    return animator;
}

static dg_component_t *set_animator(int id)
{
    dg_component_t *animator;

    switch (id) {
        case 0:
            animator = dg_cpt_animator(&set_enemy_animator_fisherman);
            break;
        case 1:
            animator = dg_cpt_animator(&set_enemy_animator_bucheron);
            break;
        case 2:
            animator = dg_cpt_animator(&set_enemy_animator_pdg);
            break;
        default:
            animator = dg_cpt_animator(&set_enemy_animator_bliblio);
            break;
    }
    return (animator);
}

dg_entity_t *entity_enemy_fight_create(int id)
{
    dg_entity_t *enemy = dg_entity_create("enemy_fight");
    dg_component_t *animator = set_animator(id);
    void *idata[2] = {enemy, animator->data};

    dg_entity_add_component(enemy, animator);
    if (id == 2)
        dg_entity_add_component(enemy, dg_cpt_pos(1250, 600));
    else if (id == 3)
        dg_entity_add_component(enemy, dg_cpt_pos(1250, 520));
    else
        dg_entity_add_component(enemy, dg_cpt_pos(1250, 500));
    dg_entity_add_component(enemy, cpt_scale(3.5, 3.5));
    return enemy;
}