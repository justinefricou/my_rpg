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

/* "", "", "", "", "", "", "", "", "", "", "",
"", "", "", "", "", "", "", "", ""*/

static const char *CLUES_DESCRIPTION[CLUES_LEN][20] = {
    {
        "According to the photographer, there was the sound of a chainsaw",
        "during a long time. Then, screams (male and female voices) and",
        "the chainsaw stopped.",
        "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
        "Use the right and left arrows to navigate through the clues"
    },
    {
        "The body has been cut in half using the logger's chainsaw.",
        "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
        "Use the right and left arrows to navigate through the clues"
    },
    {
        "According to the logger, his chainsaw was stolen and used as the",
        "weapon so people would think he is the murderer.",
        "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
        "Use the right and left arrows to navigate through the clues"
    },
    {
        "According to the policeman, the photographer is the murderer.",
        "He loves the forest and didn't want the campsite's owner to destroy",
        "it to expand his business, so he killed him.",
        "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
        "Use the right and left arrows to navigate through the clues"
    },
    {
        "According to the logger, the photographer isn't the murderer.",
        "Indeed, they are allies against the campsite's owner and the shop's",
        "owner in th battle for the forest, and the photographer wouldn't",
        "have used a weapon that would incriminate his ally (his chainsaw).",
        "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
        "Use the right and left arrows to navigate through the clues"
    },
    {
        "According to the shop owner, the campsite owner was his ally against",
        "the photographer and the logger, and he wouldn't kill his ally.",
        "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
        "Use the right and left arrows to navigate through the clues"
    },
    {
        "According to the cashier, the shop's owner has no scruples when",
        "it comes to expanding his business and earning more money. The",
        "cashier thinks he killed hiw own ally, the campsite owner, so that",
        "people would suspect the logger and the photographer, and so that",
        "he would get all the land to himself.",
        "", "", "", "", "", "", "", "", "", "", "", "", "", "",
        "Use the right and left arrows to navigate through the clues"
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