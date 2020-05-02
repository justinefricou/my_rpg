/*
** EPITECH PROJECT, 2020
** background_menu
** File description:
** background_menu
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"

static dg_animator_t *set_player_animator(void)
{
    dg_spritesheet_t *ss = dg_ressources_get_spritesheet_by_name("player");
    dg_animator_t *animator = dg_animator_create();
    dg_animation_t *anim = 0;
    char *name_list[4] = {"down", "up", "right", "left"};
    char *name_idle[4] = {"idle", "idle_u", "idle_r", "idle_l"};

    for (int i = 0; i < 4; i++) {
        anim = dg_animation_create(ss, 10);
        dg_animation_add(anim, (i * 3) + 1);
        dg_animator_add(animator, name_idle[i], anim);
    }
    for (int i = 0; i < 4; i++) {
        anim = dg_animation_create(ss, 10);
        for (int j = 0; j < 3; j++)
            dg_animation_add(anim, (i * 3) + j);
        dg_animator_add(animator, name_list[i], anim);
    }
    return animator;
}
dg_entity_t *entity_player_create(dg_scene_t *scene)
{
    dg_entity_t *player = dg_entity_create("player");
    dg_component_t *animator = dg_cpt_animator(&set_player_animator);
    void *idata[3] = {player, animator->data, scene};

    dg_entity_add_component(player, cpt_scale(3, 3));
    dg_entity_add_component(player, animator);
    dg_entity_add_component(player, cpt_script(&scp_player_controller_init,
        &scp_player_controller_loop, &scp_player_controller_end, idata));
    return player;
}