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
    dg_ressources_add_audio("./sound/button_click.ogg", "hud_activate");
    dg_ressources_add_audio("./sound/button_change.ogg", "hud_move");
}