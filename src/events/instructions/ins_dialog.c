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

parameters_t *ins_set_dialog(instruction_t *instruction, int *i,
    general_data_t *gd, int *len)
{
    parameters_t *param = malloc(sizeof(parameters_t) * 2);
    parameters_t *text_param = instruction[*i].parameters;

    param[0].type = INSTRUCTIONS;
    param[0].parameters.i = ins_set_intern(instruction, i, gd);
    param[1].type = VOID;
    *len = 1;
    return param;
}

intern_t *ins_ini_dialog(intern_t *prev, general_data_t *gd)
{
    parameters_t *params = prev->script[prev->reader.progress].parameters;
    dg_scene_t *scene = dg_scene_manager_get_scene("layer_hud");
    intern_t *intern = malloc(sizeof(intern_t));

    intern->script = params[0].parameters.i;
    for (intern->reader.len = 0; intern->script[intern->reader.len].keycode
        != NONE;
        intern->reader.len++);
    intern->reader.activation = 1;
    intern->dialog.box = ent_hud_box(45, 700, 38, 6);
    intern->dialog.ent_text = ent_text(65, 710, 50, "");
    intern->dialog.text =
        dg_entity_get_component(intern->dialog.ent_text, "text");
    dg_scene_add_ent(scene, intern->dialog.ent_text);
    dg_scene_add_ent(scene, intern->dialog.box);
    event_launch(intern, gd);
    return intern;
}

int ins_act_dialog(intern_t *intern, self_data_t data,
    dg_window_t *w, sfTime dt)
{
    general_data_t *gd = w->general_data;

    gd->lock.menu = 1;
    gd->lock.move = 1;
    event_active(intern->intern, data, w, dt);
    if (intern->intern->reader.active == 0) {
        gd->lock.menu = 0;
        gd->lock.move = 0;
        return 1;
    }
    return 0;
}

void ins_end_dialog(intern_t *intern)
{
    intern->intern->dialog.box->destroy = 1;
    intern->intern->dialog.ent_text->destroy = 1;
    free(intern->intern);
}