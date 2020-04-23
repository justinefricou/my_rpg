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
#include "epitech_tools.h"
#include "game_scenes.h"

parameters_t *ins_set_tp(instruction_t *instruction, int *i,
    general_data_t *gd)
{
    parameters_t *param = malloc(sizeof(parameters_t) * 5);
    parameters_t *text_param = instruction[*i].parameters;

    param[0].type = STRING;
    param[0].parameters.s = text_param[0].parameters.s;
    param[1].type = INT;
    param[1].parameters.n = my_atoi(text_param[1].parameters.s);
    param[2].type = INT;
    param[2].parameters.n = my_atoi(text_param[2].parameters.s);
    param[3].type = INT;
    param[3].parameters.n = my_atoi(text_param[3].parameters.s);
    param[4].type = NONE;
    return param;
}

intern_t *ins_ini_tp(void)
{
    return NULL;
}

int ins_act_tp(intern_t *intern, self_data_t self,
    general_data_t *gd)
{
    parameters_t *params = intern->script[intern->reader.progress].parameters;
    dg_scene_t *scene = dg_scene_manager_get_scene("layer_event");
    dg_entity_t *player = dg_get_entity(scene->entities, "player");
    sfVector2f *pos = NULL;

    pos = (!dg_strcmp("PLAYER", params[0].parameters.s)) ?
        dg_entity_get_component(player, "pos") : NULL;
    pos = (!dg_strcmp("SELF", params[0].parameters.s)) ?
        self.pos : pos;
    pos = (!pos) ? NULL : pos;
    if (!pos)
        return 1;
    *pos = (sfVector2f){params[1].parameters.n * 16 * 3,
        params[2].parameters.n * 16 * 3};
    return 1;
    if (!dg_strcmp("SELF", params[3].parameters.s))
        return 1;
    remove_game_scenes();
    create_game_scenes(gd, params[3].parameters.s);
    return 1;
}

void ins_end_tp(intern_t *intern)
{

}