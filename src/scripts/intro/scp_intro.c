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
#include "intro.h"

static const float intro_end = 21;

void *scp_intro_init(void *init_data)
{
    data_t *data = malloc(sizeof(data_t));

    data->added = 0;
    data->clock = 0;
    data->layer = scene_tmp_hover("tmp");
    dg_scene_manager_add_scene(data->layer);
    data->gun = set_sprite_intro("gun", data->layer,
        (sfVector2f) {0, 40}, (sfVector2f){1200, 200});
    data->dead = set_sprite_intro("corpse", data->layer,
        (sfVector2f) {0, 40}, (sfVector2f){3000, 3000});
    data->fb.entity = ent_framebuffer((sfVector2f){0, 0},
        (sfVector2i) {1920, 1080});
    data->fb.fb = dg_entity_get_component(data->fb.entity, "framebuffer");
    data->sparkle.entity = ent_sparkle(set_sparkle_intro());
    data->sparkle.pos = dg_entity_get_component(data->sparkle.entity, "pos");
    data->text.entity = ent_text(500, -300, 140, "RPG");
    data->text.pos = dg_entity_get_component(data->text.entity, "pos");
    dg_scene_add_ent(data->layer, data->fb.entity);
    return data;
}

void play_intro(data_t *data, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    (data->clock > 0.5 && data->clock < 1.5) ? gun_shot(data, dt) : NULL;
    (data->clock > 1.5 && data->clock < 6) ? ball_shot(data, dt) : NULL;
    (data->clock > 6 && data->clock < 8) ? dead_shot(data, dt) : NULL;
    (data->clock > 8 && data->clock < 20) ? island_shot(data, dt) : NULL;
}

void scp_intro_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;

    if (keymap_is_clicked(w, "action", 1) || data->clock > intro_end) {
        dg_scene_manager_remove("intro");
        dg_scene_manager_add_scene(scene_main_menu());
        dg_scene_manager_add_scene(scene_main_menu_hover());
    }
    dg_fb_fill(data->fb.fb, sfBlack);
    play_intro(data, w, entities, dt);
    data->clock += sfTime_asSeconds(dt);
    if (data->clock > 8 && data->clock < 20 && !data->added) {
        data->added = 1;
        dg_scene_add_ent(data->layer, data->sparkle.entity);
        dg_scene_add_ent(data->layer, data->text.entity);
    } else if (data->clock > 20 && data->added) {
        data->added = 0;
        data->sparkle.entity->destroy = 1;
    }
}

void scp_intro_end(void *data)
{
    data_t *d = (data_t *)data;

    dg_scene_manager_remove("tmp");
    free(d);
}