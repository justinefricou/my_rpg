/*
** EPITECH PROJECT, 2020
** ent_button
** File description:
** ent_button
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

static sfFloatRect set_text(dg_entity_t *entity, dg_component_t *ctext,
    char *content, int size)
{
    sfText *text = (sfText *)(ctext->data);
    sfFloatRect rect = {0};

    sfText_setCharacterSize(text, size);
    rect = sfText_getGlobalBounds(text);
    sfText_setPosition(text, (sfVector2f){rect.width * 0.6 - rect.left,
        rect.height * 0.2 - rect.top});
    dg_entity_add_component(entity, ctext);
    return rect;
}

static void set_button_scale(dg_entity_t *button, int size, char *text,
    dg_spritesheet_t *img)
{
    int tlen = 0;
    float img_rx = 1.0 / img->x;
    float img_ry = 1.0 / img->y;
    dg_component_t *ctext = cpt_text((sfVector2f){0, 0}, size, text);
    sfFloatRect text_size = set_text(button, ctext, text, size);
    float img_x_size = img_rx * (text_size.width * 2.2);
    float img_y_size = img_ry * (text_size.height * 1.4);

    dg_entity_add_component(button, cpt_scale(img_x_size, img_y_size));
    dg_entity_add_component(button, cpt_box_collider(0, 0,
        img_y_size * img->y, img_x_size * img->x));
}

dg_entity_t *ent_button(sfVector2f pos, int size, char *text
    , void (*action)(dg_window_t *))
{
    dg_entity_t *button = dg_entity_create("button");

    dg_entity_add_component(button, dg_cpt_pos(pos.x, pos.y));
    set_button_scale(button, size, text, dg_ressources_get_spritesheet(1));
    dg_entity_add_component(button, cpt_action(action));
    dg_entity_add_component(button, cpt_spritesheet(1));
    dg_entity_add_component(button, cpt_color((sfColor){255, 255, 255, 255}));
    return button;
}
