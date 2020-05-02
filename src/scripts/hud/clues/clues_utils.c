/*
** EPITECH PROJECT, 2020
** script_monster
** File description:
** script player controller
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "hud/hud_clues.h"

static const char *CLUES_DESCRIPTION[CLUES_LEN][20] = {
    {
        "According to the photographer, there was the sound of a chainsaw\n" \
        "during a long time. Then, screams (male and female voices) and\n" \
        "the chainsaw stopped.",
        "The body has been cut in half using the logger's chainsaw.",
        "According to the logger, his chainsaw was stolen and used as the\n" \
        "weapon so people would think he is the murderer.",
        "According to the policeman, the photographer is the murderer.\n"\
        "He loves the forest and didn't want the campsite's owner to destroy\n"\
        "it to expand his business, so he killed him.",
        "According to the logger, the photographer isn't the murderer. "\
        "Indeed,\nthey are allies against the campsite's owner and the shop's\n"\
        "owner in th battle for the forest, and the photographer wouldn't\n"\
        "have used a weapon that would incriminate his ally (his chainsaw).",
        "According to the shop owner, the campsite owner was his ally against"\
        "\nthe photographer and the logger, and he wouldn't kill his ally.",
        "According to the cashier, the shop's owner has no scruples when\n"\
        "it comes to expanding his business and earning more money. The\n"\
        "cashier thinks he killed hiw own ally, the campsite owner, so that\n"\
        "people would suspect the logger and the photographer, and so that\n"\
        "he would get all the land to himself.",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "That's all, go talk to the villagers to find more clues."
    }
};

void clues_update(data_t *data, dg_window_t *w)
{
    general_data_t *gd = w->general_data;

    for (int i = 0; i < 20; i++) {
        sfText_setString(data->text[i],
            CLUES_DESCRIPTION[gd->clues.list[data->select]][i]);
    }
}