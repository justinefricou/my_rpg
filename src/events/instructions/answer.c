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

void dialog_button(int *previous, void *data, dg_window_t *w)
{
    void **d = (void **)data;
    intern_t *intern = d[0];

    intern->script = d[1];
    intern->reader.activation = 1;
    event_launch(intern, w->general_data);
    intern->reader.end = 1;
    intern->dialog.hud_box->destroy = 1;
    free(d);
}

static button_t set_choices_buttons(intern_t *intern, parameters_t *params, general_data_t *gd)
{
    void **data = 0;
    button_t button = {0};
    int dialog_id = get_dialog_id(params[0].parameters.s, gd->dialogs);

    if (dialog_id >= 0)
        button.name = gd->dialogs.lines[dialog_id];
    else
        button.name = "";

    data = malloc(sizeof(void *) * 2);
    data[0] = intern;
    data[1] = params[1].parameters.i;
    button.data = data;
    button.action = &dialog_button;
    return button;
}

button_t *set_choices(intern_t *prev, intern_t *intern, general_data_t *gd)
{
    int len = 0;
    button_t *buttons = 0;
    parameters_t *params = 0;

    for (len = 0; prev->script[prev->reader.progress - len].keycode
        == ANSWER;
        len++);
    buttons = malloc(sizeof(button_t) * (len + 1));
    for (int i = len - 1; i >= 0; i--) {
        params = prev->script[prev->reader.progress - (len - i - 1)].parameters;
        buttons[i] = set_choices_buttons(intern, params, gd);
    }
    buttons[len].name = NULL;
    buttons[len].data = NULL;
    buttons[len].action = NULL;
    return buttons;
}