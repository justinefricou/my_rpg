/*
** EPITECH PROJECT, 2020
** ent_music
** File description:
** ent_music
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

dg_entity_t *ent_music(char *path)
{
    dg_entity_t *entity = dg_entity_create("music");
    dg_component_t *sound = cpt_sound(path);

    sound_play((sfMusic *)(sound->data));
    dg_entity_add_component(entity, sound);
    return entity;
}