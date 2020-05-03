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

static const sfColor star = {150, 130, 85, 255};

sprite_t set_sprite_intro(char *sheet, dg_scene_t *scene,
    sfVector2f id_scale, sfVector2f pos)
{
    sprite_t sprite = {0};
    dg_component_t *cpt = cpt_rot(0);

    sprite.entity = ent_sprite(dg_ressources_get_spritesheet_by_name(sheet),
        (int)id_scale.x, id_scale.y, pos);
    sprite.pos = dg_entity_get_component(sprite.entity, "pos");
    sprite.size = dg_entity_get_component(sprite.entity, "scale");
    sprite.rot = cpt->data;
    dg_entity_add_component(sprite.entity, cpt);
    dg_scene_add_ent(scene, sprite.entity);
    return sprite;
}

sparkle_context_t set_sparkle_intro(void)
{
    sparkle_context_t context = {0};

    context.density = 0.0001;
    context.duration = 5;
    context.dispersion = (sfVector2i) {1920, 600};
    context.dispersion_type = SQUARE;
    context.position = (sfVector2f) {0, -600};
    context.size = 10;
    context.color = star;
    return context;
}