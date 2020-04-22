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
    dg_ressources_add_spritesheet("./img/background.png", "background_menu",
        1920, 1080);
    dg_ressources_add_spritesheet("./img/button.png", "to_remove", 1104, 340);
    dg_ressources_add_spritesheet("./img/tileset_map.png", "map", 16, 16);
    dg_ressources_add_spritesheet("./img/tileset_HUD.png", "hud", 16, 16);
    dg_ressources_add_spritesheet("./img/icons.png", "icons", 32, 32);
    dg_ressources_add_spritesheet("./img/player.png", "player", 32, 32);
}