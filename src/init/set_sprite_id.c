/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** general data
*/

#include <stdlib.h>
#include "general_data.h"
#include "object.h"
#include "mator.h"

//butcher, barman, mayor, fisher
static dg_animator_t *mator_butcher(void)
{
    dg_spritesheet_t *ss = dg_ressources_get_spritesheet_by_name("butcher");
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

static dg_animator_t *mator_barman(void)
{
    dg_spritesheet_t *ss = dg_ressources_get_spritesheet_by_name("barman");
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

static dg_animator_t *mator_mayor(void)
{
    dg_spritesheet_t *ss = dg_ressources_get_spritesheet_by_name("mayor");
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

static dg_animator_t *mator_fisher(void)
{
    dg_spritesheet_t *ss = dg_ressources_get_spritesheet_by_name("fisher");
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

void set_sprite_id(general_data_t *gd)
{
    gd->sprite_id[0] = &mator_butcher;
    gd->sprite_id[1] = &mator_mayor;
    gd->sprite_id[2] = &mator_fisher;
    gd->sprite_id[3] = &mator_barman;
    gd->sprite_id[4] = &mator_pdg;
    gd->sprite_id[5] = &mator_camping;
    gd->sprite_id[6] = &mator_librarian;
    gd->sprite_id[7] = &mator_policeman;
    gd->sprite_id[8] = &mator_photograph;
    gd->sprite_id[9] = &mator_cashier;
    gd->sprite_id[10] = &mator_mother_one;
    gd->sprite_id[11] = &mator_mother;
    gd->sprite_id[12] = &mator_child_two;
    gd->sprite_id[13] = &mator_child_one;
    gd->sprite_id[14] = &mator_child;
    gd->sprite_id[15] = &mator_dead;
}