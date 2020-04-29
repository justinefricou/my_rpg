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

intern_t *ins_ini_move(intern_t *prev)
{
    return NULL;
}

int ins_act_move(intern_t *intern, self_data_t self,
    dg_window_t *w)
{
    general_data_t *gd = w->general_data;
    parameters_t *params = intern->script[intern->reader.progress].parameters;
    dg_scene_t *scene = dg_scene_manager_get_scene("layer_event");
    dg_entity_t *player = dg_get_entity(scene->entities, "player");
    sfVector2f *pos = NULL;
    sfVector2f target = {params[1].parameters.n * 16 * 3,
        params[2].parameters.n * 16 * 3};
    sfVector2f move = {0};

    if (!dg_strcmp("PLAYER", params[0].parameters.s)) {
         pos = dg_entity_get_component(player, "pos");
         gd->lock.menu = 1;
         gd->lock.move = 1;
    }
    pos = (!dg_strcmp("SELF", params[0].parameters.s)) ?
        self.pos : pos;
    pos = (!pos) ? NULL : pos;
    if (!pos)
        return 1;
    move.x = (pos->x > target.x) ? -1 : move.x;
    move.x = (pos->x < target.x) ? 1 : move.x;
    move.y = (pos->y > target.y) ? -1 : move.y;
    move.y = (pos->y < target.y) ? 1 : move.y;
    pos->x += move.x;
    pos->y += move.y;
    if (pos->x == target.x && pos->y == target.y) {
        gd->lock.menu = 0;
        gd->lock.move = 0;
        return 1;
    }
    return 0;
}

void ins_end_move(intern_t *intern)
{

}