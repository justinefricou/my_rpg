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

intern_t *ins_ini_talk(intern_t *prev)
{
    return NULL;
}

int ins_act_talk(intern_t *intern, self_data_t data,
    dg_window_t *w)
{
    parameters_t *params = intern->script[intern->reader.progress].parameters;

    sfText_setString(intern->dialog.text, params[0].parameters.s);
    if (keymap_is_clicked(w, "action", 1)) {
        sound_play(dg_ressources_get_audio_by_name("hud_activate"));
        return 1;
    }
    return 0;
}

void ins_end_talk(intern_t *intern)
{

}