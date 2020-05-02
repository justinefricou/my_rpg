/*
** EPITECH PROJECT, 2020
** attack_fight
** File description:
** attack_fight
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "hud/hud_inventory.h"
#include "game_scenes.h"
#include "fight_scenes.h"

void skill_attack(int *previous, void *data, dg_window_t *w)
{
    dg_scene_t *scene = dg_scene_manager_get_scene("layer_hud_fight");
    general_data_t *gd = w->general_data;
    int i = *((int *)data);
    float mult = 1;

    dg_scene_add_ent(scene, ent_hud_fight_dialogue(previous, scene, i, gd));
    if (gd->skills[i].type == gd->enemy.type ||
        -2 == (gd->enemy.type - gd->skills[i].type) ||
        2 == (gd->enemy.type - gd->skills[i].type))
        mult = 1;
    else if (-1 == (gd->enemy.type - gd->skills[i].type))
        mult = 2;
    else
        mult = 0.5;
    gd->enemy.pv.x -= (gd->player.damage * mult);
}

static void close_fight(void)
{
    sfMusic_play(dg_ressources_get_audio_by_name("game_theme"));
    sfMusic_stop(dg_ressources_get_audio_by_name("fight_theme"));
    remove_fight_scenes();
}

void end_battle(dg_entity_t *entity, dg_window_t *w)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;
    dg_scene_t *game_scenes[NB_GAME_SCENE];
    general_data_t *gd = w->general_data;

    if (gd->enemy.pv.x <= 0 || gd->player.pv.x <= 0) {
        sound_play(data->sound_activate);
        entity->destroy = 1;
        if (gd->enemy.pv.x <= 0)
            gd->event_manager.var[variable_to_int("BATTLE", gd)].data = 1;
        else
            gd->event_manager.var[variable_to_int("BATTLE", gd)].data = 0;
        get_game_scenes(&game_scenes, 1);
        for (int i = 0; i < NB_GAME_SCENE; i++) {
            game_scenes[i]->display = 1;
            game_scenes[i]->run = 1;
        }
        close_fight();
    }
}