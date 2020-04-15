/*
** EPITECH PROJECT, 2020
** init_img
** File description:
** init_img
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

void init_audio(void)
{
    dg_ressources_add_audio("./sound/button_click.ogg", "hud_activate", 1);
    dg_ressources_add_audio("./sound/button_change.ogg", "hud_move", 1);
    dg_ressources_add_audio("./sound/menu_song.ogg", "menu_theme", 0);
    dg_ressources_add_audio("./sound/theme_game.ogg", "game_theme", 0);
}