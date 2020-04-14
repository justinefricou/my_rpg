/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** objects
*/

#ifndef OBJECT_H_
#define OBJECT_H_

#include "libdragon.h"

typedef void (*object_action_t)(dg_window_t *w);

typedef struct object
{
    char *name;
    dg_spritesheet_t *sheet;
    int icon_id;
    object_action_t action;
} object_t;

object_t object_create(char *name, int icon_id, object_action_t effect);
object_t object_get_by_name(object_t *objects, int len, char *name);

#endif /*OBJECT_H_*/
