/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** general data
*/

#include <stdlib.h>
#include "general_data.h"
#include "object.h"

static dg_animator_t *animation_one(void)
{
    dg_spritesheet_t *ss = dg_ressources_get_spritesheet_by_name("player");
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

void set_sprite_id(general_data_t *gd)
{
    gd->sprite_id[0] = &animation_one;
}