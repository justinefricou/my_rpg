/*
** EPITECH PROJECT, 2020
** init_img
** File description:
** init_img
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

void init_img(void)
{
    dg_ressources_add_spritesheet("./img/background.png", 1920, 1080);
    dg_ressources_add_spritesheet("./img/button.png", 1104, 340);
    dg_ressources_add_spritesheet("./img/tileset_map.png", 16,16);
    dg_ressources_add_spritesheet("./img/panel.png", 626, 417);
    dg_ressources_add_spritesheet("./img/player.png", 32, 32);
    dg_ressources_add_spritesheet("./img/tileset_HUD.png", 16, 16);
}