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
#include "game_scenes.h"
#include "fight_scenes.h"

parameters_t *ins_set_battle(instruction_t *instruction, int *i,
    general_data_t *gd, int *len)
{
    parameters_t *param = malloc(sizeof(parameters_t) * 2);
    parameters_t *text_param = instruction[*i].parameters;

    param[0].type = INT;
    param[0].parameters.n = my_atoi(text_param[0].parameters.s);
    param[1].type = VOID;
    *len = 1;
    return param;
}

intern_t *ins_ini_battle(intern_t *prev, general_data_t *gd)
{
    return NULL;
}

int ins_act_battle(intern_t *intern, self_data_t data,
    dg_window_t *w, sfTime dt)
{
    dg_scene_t *game[NB_GAME_SCENE];
    parameters_t *params = intern->script[intern->reader.progress].parameters;

    get_game_scenes(game, 1);
    for (int i = 0; i < NB_GAME_SCENE; i++) {
        game[i]->display = 0;
        game[i]->run = 0;
    }
    create_fight_scenes(w, params[0].parameters.n);
    sfMusic_stop(dg_ressources_get_audio_by_name("game_theme"));
    sfMusic_play(dg_ressources_get_audio_by_name("fight_theme"));
    return 1;
}

void ins_end_battle(intern_t *intern)
{

}