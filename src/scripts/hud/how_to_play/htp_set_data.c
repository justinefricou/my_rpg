/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** how to play
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "hud/hud_htp.h"

static const char *text[20] = {
    "> This game is a riddle rpg game.",
    "> A murder happened and as an inspector you have to solve this",
    "> riddle. Use all your strength to get clues by studying places and",
    "> interrogate people during arguments battles !",
    "> Level up your competences and use your brain to finally triumph",
    "> over the lies and make justice to the poor dead beings.",
    "> ",
    "> Controls (default) :",
    "> Up : up arrow",
    "> Down : Down arrow",
    "> Left : left arrow",
    "> Right : right arrow",
    "> Action : space",
    "> Cancel / Menu : Escape",
    ">",
    "> You can change the keymapping in the options,",
    "> Available at any time in the game.",
    ">",
    "> Please, enjoy our game and have fun !",
    "> Alexia, Mathias, Justine and Vito."
};

void htp_set_sounds(data_t *data)
{
    data->sound_activate = dg_ressources_get_audio_by_name("hud_activate");
}

void htp_set_text(data_t *data)
{
    int lines = 20;

    dg_scene_add_ent(data->layer,
            ent_text(950, 20, 70, "How to play"));
    for (int i = 0; i < lines; i++)
        dg_scene_add_ent(data->layer,
            ent_text(540, 140 + i * 40, 30, (char *)text[i]));
}