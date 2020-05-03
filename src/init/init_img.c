/*
** EPITECH PROJECT, 2020
** init_img
** File description:
** init_img
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

static img_add_characters(void)
{
    dg_ressources_add_spritesheet("./img/fisher.png", "fisher", 16, 16);
    dg_ressources_add_spritesheet("./img/mayor.png", "mayor", 16, 16);
    dg_ressources_add_spritesheet("./img/pdg.png", "pdg", 16, 16);
    dg_ressources_add_spritesheet("./img/camping.png", "camping", 16, 16);
    dg_ressources_add_spritesheet("./img/librarian.png", "librarian", 16, 16);
    dg_ressources_add_spritesheet("./img/policeman.png", "policeman", 16, 16);
    dg_ressources_add_spritesheet("./img/photograph.png",
        "photograph", 16, 16);
    dg_ressources_add_spritesheet("./img/cashier.png", "cashier", 16, 16);
    dg_ressources_add_spritesheet("./img/mother2.png", "mother_one", 16, 16);
    dg_ressources_add_spritesheet("./img/mother.png", "mother", 16, 16);
    dg_ressources_add_spritesheet("./img/child3.png", "child_two", 16, 16);
    dg_ressources_add_spritesheet("./img/child2.png", "child_one", 16, 16);
    dg_ressources_add_spritesheet("./img/child.png", "child", 16, 16);
    dg_ressources_add_spritesheet("./img/dead.png", "dead", 16, 16);
}

void init_img(void)
{
    dg_ressources_add_spritesheet("./img/button.png", "to_remove", 1104, 340);
    dg_ressources_add_spritesheet("./img/tileset_map.png", "map", 16, 16);
    dg_ressources_add_spritesheet("./img/tileset_HUD.png", "hud", 16, 16);
    dg_ressources_add_spritesheet("./img/icons.png", "icons", 32, 32);
    dg_ressources_add_spritesheet("./img/player.png", "player", 16, 16);
    dg_ressources_add_spritesheet("./img/background_fight_1.png",
        "background_fight_1", 1272, 253);
    dg_ressources_add_spritesheet("./img/player_fight.png",
        "player_fight", 90, 195);
    dg_ressources_add_spritesheet("./img/enemy_1.png", "enemy_1", 72, 148);
    dg_ressources_add_spritesheet("./img/enemy_2.png", "enemy_2", 104, 162);
    dg_ressources_add_spritesheet("./img/enemy_3.png", "enemy_3", 112, 123);
    dg_ressources_add_spritesheet("./img/enemy_4.png", "enemy_4", 76, 143);
    dg_ressources_add_spritesheet("./img/intro_gun.png", "gun", 16, 16);
    dg_ressources_add_spritesheet("./img/intro_dead.png", "corpse", 10, 15);
    dg_ressources_add_spritesheet("./img/enemy_5.png", "enemy_5", 97, 149);
    img_add_characters();
}