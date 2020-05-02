/*
** EPITECH PROJECT, 2020
** script_monster
** File description:
** script player controller
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "hud/hud_inventory.h"
#include "game_scenes.h"

static button_t *create_select_box(general_data_t *gd)
{
    int i = 0;
    int *n = 0;
    for (; gd->skills[i].name != NULL; i++);
    button_t *button_list = malloc(sizeof(button_t) * (i + 1));

    for (i = 0; gd->skills[i].name != NULL; i++) {
        n = malloc(sizeof(int));
        *n = i;
        button_list[i] = (button_t){gd->skills[i].name, &skill_attack, n};
    }
    button_list[i] = (button_t){NULL, NULL, NULL};
    return button_list;
}

void *scp_hud_fight_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    dg_scene_t *scene = idata[1];
    dg_entity_t *entity = idata[0];
    general_data_t *gd = idata[3];
    button_t *button_list = create_select_box(gd);

    data->sound_activate = dg_ressources_get_audio_by_name("hud_activate");
    data->sound_move = dg_ressources_get_audio_by_name("hud_move");
    data->previous = idata[2];
    data->skill_box = ent_hud_menu_selector((sfVector2f){350, 20},
        button_list, scene, 1);
    data->launch_action = 0;
    dg_scene_add_ent(scene, data->skill_box);
    return data;
}

static void inventory_menu_active(dg_window_t *w, data_t *data,
    dg_entity_t *entity)
{
    general_data_t *gd = w->general_data;

    inventory_manage_move(w, data);
    if (keymap_is_clicked(w, "cancel", 1)) {
        sound_play(data->sound_activate);
        entity->destroy = 1;
    }
    if (keymap_is_clicked(w, "action", 0)) {
        data->is_active = 0;
        data->launch_action = 1;
    }
}

void scp_hud_fight_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;
    general_data_t *gd = w->general_data;
    dg_scene_t *game_scenes[NB_GAME_SCENE];

    inventory_menu_active(w, data, entity);
    if (gd->enemy.pv.x <= 0) {
        sound_play(data->sound_activate);
        entity->destroy = 1;
        gd->event_manager.var[variable_to_int("BATTLE", gd)].data = 1;
        get_game_scenes(&game_scenes, 1);
        for (int i = 0; i < NB_GAME_SCENE; i++) {
            game_scenes[i]->display = 1;
            game_scenes[i]->run = 1;
        }
        sfMusic_play(dg_ressources_get_audio_by_name("game_theme"));
        sfMusic_stop(dg_ressources_get_audio_by_name("fight_theme"));
        remove_fight_scenes();
    }
}

void scp_hud_fight_end(void *data)
{
    data_t *d = (data_t *)data;

    dg_scene_manager_remove("slots");
    *(d->previous) = 1;
    d->skill_box->destroy = 1;
    free(d);
}