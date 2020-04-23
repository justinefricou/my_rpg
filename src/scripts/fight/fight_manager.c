/*
** EPITECH PROJECT, 2020
** fight_manager
** File description:
** fight_manager
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"

typedef struct data {
    int id;
} data_t;

void *scp_fight_manager_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));

    data->id = idata[0];
    return data;
}

void scp_fight_manager_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;
}

void scp_fight_manager_end(void *data)
{
    data_t *d = (data_t *)data;

    free(d);
}