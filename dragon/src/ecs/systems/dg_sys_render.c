/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** system : render
*/

#include <stdlib.h>
#include "libdragon.h"
#include "epitech_tools.h"

void dg_camera_render(sfVector2f camera, sfSprite *sprite, dg_window_t *w)
{
    sfVector2f reverse = {-camera.x, -camera.y};

    sfSprite_move(sprite, reverse);
    sfRenderWindow_drawSprite(w->window, sprite, NULL);
    sfSprite_move(sprite, camera);
}

void dg_camera_transform(sfVector2f camera, sfVector2f pos)
{
    sfVector2f reverse = {-camera.x, -camera.y};

    return (sfVector2f){pos.x + reverse.x, pos.y + reverse.y};
}