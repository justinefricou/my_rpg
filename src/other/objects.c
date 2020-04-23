/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** objects
*/

#include "object.h"
#include "libdragon.h"
#include "epitech_tools.h"

object_t object_get_by_name(object_t *objects, int len, char *name)
{
    for (int i = 0; i < len; i++) {
        if (!dg_strcmp(objects[i].name, name))
            return objects[i];
    }
    return (object_t){0};
}

int object_get_id_by_name(object_t *objects, int len, char *name)
{
    for (int i = 0; i < len; i++) {
        if (!dg_strcmp(objects[i].name, name))
            return i;
    }
    return -1;
}