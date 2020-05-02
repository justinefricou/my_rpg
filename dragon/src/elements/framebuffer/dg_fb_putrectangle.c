/*
** EPITECH PROJECT, 2019
** draw a square
** File description:
** draw rectangles
*/

#include "dragon/dg_framebuffer.h"

void dg_fb_putsquare(dg_framebuffer_t *fb, sfVector2u position,
    unsigned int size, sfColor color)
{
    for (int i = position.x; i < position.x + size; i++)
        for (int j = position.y; j < position.y + size; j++)
            dg_fb_putpx(fb, i, j, color);
}

//draw a rectangle
void dg_fb_putrectangle(dg_framebuffer_t *fb, sfVector2u position,
    sfVector2u size, sfColor color)
{
    for (int i = position.x; i < position.x + size.x; i++)
        for (int j = position.y; j < position.y + size.y; j++)
            dg_fb_putpx(fb, i, j, color);
}

//fill framebuffer
void dg_fb_fill(dg_framebuffer_t *fb, sfColor color)
{
    for (int i = 0; i < fb->width * fb->height; i++) {
        fb->pixels[i * 4] = color.r;
        fb->pixels[(i * 4) + 1] = color.g;
        fb->pixels[(i * 4) + 2] = color.b;
        fb->pixels[(i * 4) + 3] = color.a;
    }
}
