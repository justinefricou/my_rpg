/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** objects
*/

#include "object.h"
#include "libdragon.h"
#include "epitech_tools.h"

object_t object_create(char *name, int icon_id, object_action_t effect)
{
    object_t obj = {0};

    obj.name = name;
    obj.sheet = dg_ressources_get_spritesheet_by_name("icons");
    obj.icon_id = icon_id;
    obj.action = effect;
    return obj;
}

object_t object_get_by_name(object_t *objects, int len, char *name)
{
    for (int i = 0; i < len; i++) {
        if (!dg_strcmp(objects[i].name, name))
            return objects[i];
    }
    return (object_t){0};
}
