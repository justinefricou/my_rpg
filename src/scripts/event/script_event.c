/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** script player controller
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "tilemap.h"
#include "general_data.h"
#include "epitech_tools.h"

typedef struct data {
    sfVector2f *pos;
    dg_component_t *animator;
    instruction_t *script;
    int len;
    int progress;
    int active;
    int activation;
} data_t;

void get_event_from_name(char *name,
    general_data_t *gd, data_t *data)
{
    data->script = NULL;
    data->len = 0;
    for (int i = 0; i < gd->event_manager.event_len; i++)
        if (!dg_strcmp(gd->event_manager.events[i].name, name)) {
            data->script = gd->event_manager.events[i].parameters;
            data->len = gd->event_manager.events[i].len;
        }
}

void *scp_event_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    map_events_t mev_data = *((map_events_t *)idata[0]);
    dg_entity_t *entity = idata[2];
    general_data_t *gd = idata[1];
    dg_component_t *pos = dg_cpt_pos(mev_data.pos.x * (16 * 3),
        mev_data.pos.y * (16 * 3));
    
    data->progress = 0;
    get_event_from_name(mev_data.name, gd, data);
    data->activation = mev_data.interaction;
    data->active = mev_data.interaction;
    data->pos = pos->data;
    if (mev_data.animator_id >= 0) {
        data->animator = dg_cpt_animator(
        (gd->sprite_id[mev_data.animator_id]));
        dg_entity_add_component(entity, data->animator);
    }
    dg_entity_add_component(entity, pos);
    return data;
}

void event_active(data_t *data)
{

}

void scp_event_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;

    if (data->activation) {
        data->progress = 0;
        data->active = 1;
        data->activation = 0;
    }
    if (data->active) {
        event_active(data);
    }
}

void scp_event_end(void *data)
{
    data_t *d = (data_t *)data;

    free(d);
}