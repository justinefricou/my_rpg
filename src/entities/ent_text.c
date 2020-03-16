/*
** EPITECH PROJECT, 2020
** text_menu
** File description:
** text_menu
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

dg_entity_t *ent_text(int x, int y, int scale, char *text)
{
    dg_entity_t *ctext = dg_entity_create("text");

    dg_entity_add_component(ctext, dg_cpt_pos(x, y));
    dg_entity_add_component(ctext, cpt_text((sfVector2f){0, 0}, scale, text));
    return ctext;
}
