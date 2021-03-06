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
    char *description;
    dg_spritesheet_t *sheet;
    int icon_id;
    int consomable;
    object_action_t action;
    int price;
} object_t;

object_t object_get_by_name(object_t *objects, int len, char *name);
int object_get_id_by_name(object_t *objects, int len, char *name);

//objects
object_t calming(void);
object_t energy_drink(void);

#endif /*OBJECT_H_*/
