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

sprite_t set_sprite_intro(char *sheet, dg_scene_t *scene,
    sfVector2f id_scale, sfVector2f pos)
{
    sprite_t sprite = {0};

    sprite.entity = ent_sprite(dg_ressources_get_spritesheet_by_name(sheet),
        (int)id_scale.x, id_scale.y, pos);
    sprite.pos = dg_entity_get_component(sprite.entity, "pos");
    sprite.size = dg_entity_get_component(sprite.entity, "scale");
    dg_scene_add_ent(scene, sprite.entity);
    return sprite;
}

void *scp_intro_init(void *init_data)
{
    data_t *data = malloc(sizeof(data_t));

    data->clock = 0;
    data->layer = scene_tmp_hover("tmp");
    dg_scene_manager_add_scene(data->layer);
    data->gun = set_sprite_intro("player", data->layer,
        (sfVector2f) {3, 10}, (sfVector2f){500, 500});
    return data;
}

void play_intro(data_t *data, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    if(data->clock < 2)
        data->gun.pos->y += sfTime_asMilliseconds(dt);

}

void scp_intro_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;

    if (keymap_is_clicked(w, "action", 1)) {
        dg_scene_manager_remove("intro");
        dg_scene_manager_add_scene(scene_main_menu());
        dg_scene_manager_add_scene(scene_main_menu_hover());
    }
    play_intro(data, w, entities, dt);
    data->clock += sfTime_asSeconds(dt);
}

void scp_intro_end(void *data)
{
    data_t *d = (data_t *)data;

    dg_scene_manager_remove("tmp");
    free(d);
}