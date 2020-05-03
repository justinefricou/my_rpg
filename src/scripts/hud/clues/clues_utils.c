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
        "According to the photographer, the chainsaw was working",
        "for a long time. Then, he heard screams (male and female)",
        "and then the chainsaw stopped.",
        "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
        "Use the right and left arrows to navigate through the clues"
    },
    {
        "The body has been cut in half using the logger's chainsaw.",
        "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
        "Use the right and left arrows to navigate through the clues"
    },
    {
        "According to the logger, his chainsaw was stolen and turned on for",
        "a long time before being used as the weapon, so that people would",
        "think he was cutting wood when he saw Rob, the campsite owner, and",
        "decided to kill him",
        "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
        "Use the right and left arrows to navigate through the clues"
    },
    {
        "According to the policeman, the photographer is the murderer.",
        "He loves the forest and didn't want the campsite's owner to destroy",
        "it just to expand his business, so he killed him.",
        "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
        "Use the right and left arrows to navigate through the clues"
    },
    {
        "According to the logger, the photographer isn't the murderer.",
        "Indeed, they are allies against the campsite's owner and the shop's",
        "owner in the battle for the forest, and the photographer wouldn't",
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
        "cashier thinks he killed his own ally, the campsite owner, so that",
        "people would suspect the logger and the photographer, and so that",
        "he would get all the land to himself.",
        "", "", "", "", "", "", "", "", "", "", "", "", "", "",
        "Use the right and left arrows to navigate through the clues"
    },
    {
        "According to some newspapers, the shop owner has a habit of taking",
        "small businesses to court to expand his own company, even if it",
        "means destroying people's livelihoods in the process.",
        "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
        "Use the right and left arrows to navigate through the clues"
    },
    {
        "According to the fisherman, it's the 'monster of the lake' who killed",
        "the campsite owner. The logger had made too much noise using his",
        "chainswaw to whole afternoon, so the monster got angry and came out",
        "of the water to kill the first person he saw.",
        "The fisherman wouldn't talk about anything else.",
        "", "", "", "", "", "", "", "", "", "", "", "", "", "",
        "Use the right and left arrows to navigate through the clues"
    },
    {
        "According to a woman, when the lumberjack is cutting wood,",
        "he doesn't notice people around him because of the noise and the",
        "sawdust.",
        "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
        "Use the right and left arrows to navigate through the clues"
    },
    {
        "The librarian is the logger's fiance. Few people know because",
        "Jack doesn't come from a wealthy family so the librarian's family",
        "is firmly against this union.",
        "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
        "Use the right and left arrows to navigate through the clues"
    },
    {
        "According to the librarian, she and her fiance were at the bar when",
        "the murder happened.",
        "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
        "Use the right and left arrows to navigate through the clues"
    },
    {
        "According to a woman, the barman had to close his bar for the whole",
        "afternoon 3 days ago.",
        "Also, apparently your awesome socks make you look like a former",
        "alcohol addict. Too flashy ?",
        "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
        "Use the right and left arrows to navigate through the clues"
    },
    {
        "According to a child, the monster of the lake is the murderer. He",
        "can't go play in the forest since what happened 3 days ago.",
        "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
        "Use the right and left arrows to navigate through the clues"
    },
    {
        "According to a woman, Lily, who is the librarian, has a bike",
        "which stopped working 4 days ago. She said she would go ask Jack",
        "for help the next day.",
        "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
        "Use the right and left arrows to navigate through the clues"
    },
    {
        "According to the policeman, letters from Mr Bezoz were found in",
        "Rob's house after his death. In these letters, Mr Bezoz say they",
        "should 'get rid of any difficulties', and the last letter, which",
        "dates back to a week ago, says they should 'start taking actions",
        "in a few days'.",
        "The policeman thinks they intended to kill Jack and Matt.",
        "", "", "", "", "", "", "", "", "", "", "", "", "",
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