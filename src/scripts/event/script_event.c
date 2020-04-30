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
#include "event.h"
#include "instructions.h"
#include "script_event_data.h"

const key_ini_t key_init[14] = {
    NULL, &ins_ini_set, &ins_ini_if, &ins_ini_while, &ins_ini_for,
    &ins_ini_end, &ins_ini_give, &ins_ini_take, &ins_ini_tp, &ins_ini_dialog,
    &ins_ini_talk, &ins_ini_answer, &ins_ini_battle, &ins_ini_move};

const key_act_t key_active[14] = {
    NULL, &ins_act_set, &ins_act_if, &ins_act_while, &ins_act_for,
    &ins_act_end, &ins_act_give, &ins_act_take, &ins_act_tp, &ins_act_dialog,
    &ins_act_talk, &ins_act_answer, &ins_act_battle, &ins_act_move};

const key_end_t key_end[14] = {
    NULL, &ins_end_set, &ins_end_if, &ins_end_while, &ins_end_for,
    &ins_end_end, &ins_end_give, &ins_end_take, &ins_end_tp, &ins_end_dialog,
    &ins_end_talk, &ins_end_answer, &ins_end_battle, &ins_end_move};

void set_self_data(data_t *data, map_events_t mev_data,
    dg_entity_t *entity, general_data_t *gd)
{
    dg_component_t *pos = dg_cpt_pos(mev_data.pos.x * (16 * 3),
        mev_data.pos.y * (16 * 3));
    dg_component_t *anim_cpt = 0;

    get_event_from_name(mev_data.name, gd, data);
    if (mev_data.animator_id >= 0) {
        anim_cpt = dg_cpt_animator(
        (gd->sprite_id[mev_data.animator_id]));
        data->self.animator = anim_cpt->data;
        dg_entity_add_component(entity, anim_cpt);
    }
    data->self.pos = pos->data;
    data->self.memory = (sfVector2f) {data->self.pos->x, data->self.pos->y};
    dg_entity_add_component(entity, pos);
}

void *scp_event_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    map_events_t mev_data = *((map_events_t *)idata[0]);
    dg_entity_t *entity = idata[2];
    general_data_t *gd = idata[1];

    set_self_data(data, mev_data, entity, gd);
    data->intern.reader.activation = mev_data.interaction;
    data->intern.reader.active = 0;
    data->intern.reader.end = 0;
    data->intern.reader.progress = 0;
    data->intern.intern = NULL;
    return data;
}

void scp_event_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;
    general_data_t *gd = w->general_data;

    set_collision(data, entities, w);
    event_launch(&(data->intern), gd);
    event_active(&(data->intern), data->self, w, dt);
    check_interaction(data, entities, w);
}

void scp_event_end(void *data)
{
    data_t *d = (data_t *)data;

    free(d);
}