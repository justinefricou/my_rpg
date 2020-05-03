/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** general data
*/

#include <stdlib.h>
#include "general_data.h"
#include "object.h"

dg_animator_t *mator_child(void)
{
    dg_spritesheet_t *ss = dg_ressources_get_spritesheet_by_name("child");
    dg_animator_t *animator = dg_animator_create();
    dg_animation_t *anim = 0;
    char *name_list[4] = {"down", "up", "right", "left"};

    anim = dg_animation_create(ss, 10);
    dg_animation_add(anim, 1);
    dg_animator_add(animator, "idle", anim);
    for (int i = 0; i < 4; i++) {
        anim = dg_animation_create(ss, 10);
        for (int j = 0; j < 3; j++)
            dg_animation_add(anim, (i * 3) + j);
        dg_animator_add(animator, name_list[i], anim);
    }
    return animator;
}

dg_animator_t *mator_child_one(void)
{
    dg_spritesheet_t *ss = dg_ressources_get_spritesheet_by_name("child_one");
    dg_animator_t *animator = dg_animator_create();
    dg_animation_t *anim = 0;
    char *name_list[4] = {"down", "up", "right", "left"};

    anim = dg_animation_create(ss, 10);
    dg_animation_add(anim, 1);
    dg_animator_add(animator, "idle", anim);
    for (int i = 0; i < 4; i++) {
        anim = dg_animation_create(ss, 10);
        for (int j = 0; j < 3; j++)
            dg_animation_add(anim, (i * 3) + j);
        dg_animator_add(animator, name_list[i], anim);
    }
    return animator;
}

dg_animator_t *mator_child_two(void)
{
    dg_spritesheet_t *ss = dg_ressources_get_spritesheet_by_name("child_two");
    dg_animator_t *animator = dg_animator_create();
    dg_animation_t *anim = 0;
    char *name_list[4] = {"down", "up", "right", "left"};

    anim = dg_animation_create(ss, 10);
    dg_animation_add(anim, 1);
    dg_animator_add(animator, "idle", anim);
    for (int i = 0; i < 4; i++) {
        anim = dg_animation_create(ss, 10);
        for (int j = 0; j < 3; j++)
            dg_animation_add(anim, (i * 3) + j);
        dg_animator_add(animator, name_list[i], anim);
    }
    return animator;
}