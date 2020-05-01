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
#include "give.h"

parameters_t *ins_set_move(instruction_t *instruction, int *i,
    general_data_t *gd, int *len)
{
    parameters_t *param = malloc(sizeof(parameters_t) * 4);
    parameters_t *text_param = instruction[*i].parameters;

    param[0].type = STRING;
    param[0].parameters.s = text_param[0].parameters.s;
    param[1].type = INT;
    param[1].parameters.n = my_atoi(text_param[1].parameters.s);
    param[2].type = INT;
    param[2].parameters.n = my_atoi(text_param[2].parameters.s);
    param[3].type = VOID;
    *len = 3;
    return param;
}

intern_t *ins_ini_move(intern_t *prev, general_data_t *gd)
{
    return NULL;
}

int ins_act_move(intern_t *intern, self_data_t self,
    dg_window_t *w, sfTime dt)
{
    general_data_t *gd = w->general_data;
    parameters_t *params = intern->script[intern->reader.progress].parameters;
    sfVector2f target = {params[1].parameters.n * 16 * 3,
        params[2].parameters.n * 16 * 3};
    dg_animator_t *mator = 0;
    sfVector2f *pos = set_move_target(self, gd, params, &mator);
    sfVector2f move = move_set_move(pos, target);

    move_set_animation(move, mator);
    move_set_collision(self, w);
    pos->x += move.x * dt.microseconds / 10000.0 * 1.5;
    pos->y += move.y * dt.microseconds / 10000.0 * 1.5;
    if (pos->x - 5 < target.x && pos->x + 5 > target.x &&
        pos->y - 5 < target.y && pos->y + 5 > target.y) {
        gd->lock.menu = 0;
        gd->lock.move = 0;
        dg_animator_set_animation(mator, "idle");
        return 1;
    }
    return 0;
}

void ins_end_move(intern_t *intern)
{

}