/*
** EPITECH PROJECT, 2020
** background_menu
** File description:
** background_menu
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "libmy.h"
#include "general_data.h"
#include "instructions.h"
#include "script_event_data.h"
#include "answer.h"

parameters_t *ins_set_answer(instruction_t *instruction, int *i,
    general_data_t *gd, int *len)
{
    parameters_t *param = malloc(sizeof(parameters_t) * 3);
    parameters_t *text_param = instruction[*i].parameters;

    param[0].type = STRING;
    param[0].parameters.s = text_param[0].parameters.s;
    param[1].type = INSTRUCTIONS;
    param[1].parameters.i = ins_set_intern(instruction, i, gd);
    param[2].type = VOID;
    *len = 2;
    return param;
}

intern_t *ins_ini_answer(intern_t *prev, general_data_t *gd)
{
    intern_t *intern = 0;
    parameters_t *params = prev->script[prev->reader.progress].parameters;
    dg_scene_t *scene = dg_scene_manager_get_scene("layer_hud");

    if (prev->script[prev->reader.progress + 1].keycode == ANSWER)
        return NULL;
    intern = malloc(sizeof(intern_t));
    intern->dialog = prev->dialog;
    intern->script = params[0].parameters.i;
    intern->reader.activation = 0;
    intern->reader.progress = 0;
    intern->reader.active = 0;
    intern->reader.end = 0;
    intern->dialog.hud_box = ent_hud_menu_selector((sfVector2f){1500, 400},
        set_choices(prev, intern, gd), scene, 1);
    dg_scene_add_ent(scene, intern->dialog.hud_box);
    return intern;
}

int ins_act_answer(intern_t *intern, self_data_t data,
    dg_window_t *w, sfTime dt)
{
    if (intern->script[intern->reader.progress + 1].keycode == ANSWER)
        return 1;
    event_active(intern->intern, data, w, dt);
    if (intern->intern->reader.active == 0 && intern->intern->reader.end) {
        return 1;
    }
    return 0;
}

void ins_end_answer(intern_t *intern)
{
    if (intern->script[intern->reader.progress + 1].keycode == ANSWER)
        return;
}