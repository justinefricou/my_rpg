/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** general data
*/

#include <stdlib.h>
#include "general_data.h"

//dead
dg_animator_t *mator_dead(void)
{
    dg_spritesheet_t *ss = dg_ressources_get_spritesheet_by_name("dead");
    dg_animator_t *animator = dg_animator_create();
    dg_animation_t *anim = dg_animation_create(ss, 10);

    dg_animation_add(anim, 0);
    dg_animator_add(animator, "idle", anim);
    return animator;
}