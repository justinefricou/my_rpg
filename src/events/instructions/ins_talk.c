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
#include "init_dialogs.h"

parameters_t *ins_set_talk(instruction_t *instruction, int *i,
    general_data_t *gd, int *len)
{
    parameters_t *param = malloc(sizeof(parameters_t) * 2);
    parameters_t *text_param = instruction[*i].parameters;

    param[0].type = STRING;
    param[0].parameters.s = text_param[0].parameters.s;
    param[1].type = NONE;
    *len = 1;
    return param;
}

intern_t *ins_ini_talk(intern_t *prev, general_data_t *gd)
{
    return NULL;
}

int ins_act_talk(intern_t *intern, self_data_t data,
    dg_window_t *w, sfTime dt)
{
    general_data_t *gd = w->general_data;
    parameters_t *params = intern->script[intern->reader.progress].parameters;
    int dialog_id = get_dialog_id(params[0].parameters.s, gd->dialogs);

    if (dialog_id >= 0)
        sfText_setString(intern->dialog.text, gd->dialogs.lines[dialog_id]);
    else
        sfText_setString(intern->dialog.text, "");
    if (keymap_is_clicked(w, "action", 1)) {
        sound_play(dg_ressources_get_audio_by_name("hud_activate"));
        return 1;
    }
    return 0;
}

void ins_end_talk(intern_t *intern)
{

}