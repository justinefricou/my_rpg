/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** cpt_text
*/

#include <stdlib.h>
#include "dg_component.h"
#include "ecs.h"

static void component_destroy(void *data)
{
    sfText *text = (sfText *)(data);

    sfFont_destroy((sfFont *) sfText_getFont(text));
    sfText_destroy(text);
}

dg_component_t *cpt_text(sfVector2f pos, int scale, char *content)
{
    void (*destroy)(void *) = &component_destroy;
    sfText *text = sfText_create();
    dg_component_t *component = dg_component_create("text", text, destroy);

    sfText_setPosition(text, pos);
    sfText_setFont (text, sfFont_createFromFile("./font/slkscr.ttf"));
    sfText_setCharacterSize(text, scale);
    sfText_setString(text, content);
    return component;
}
