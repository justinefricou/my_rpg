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
#include "hud/hud_options.h"

static void reset_selected(data_t *data)
{
    hud_progress_bar_activate(data->content.volume_general.data, 0);
    hud_progress_bar_activate(data->content.volume_music.data, 0);
    hud_progress_bar_activate(data->content.volume_sound.data, 0);
    hud_keymap_button_activate(data->content.keymap_action.data, 0);
    hud_keymap_button_activate(data->content.keymap_cancel.data, 0);
    hud_keymap_button_activate(data->content.keymap_down.data, 0);
    hud_keymap_button_activate(data->content.keymap_left.data, 0);
    hud_keymap_button_activate(data->content.keymap_right.data, 0);
    hud_keymap_button_activate(data->content.keymap_up.data, 0);
}

void act_by_selected(data_t *data)
{
    reset_selected(data);
    (data->select == 0) ?
        hud_progress_bar_activate(data->content.volume_general.data, 1) : NULL;
    (data->select == 1) ?
        hud_progress_bar_activate(data->content.volume_music.data, 1) : NULL;
    (data->select == 2) ?
        hud_progress_bar_activate(data->content.volume_sound.data, 1) : NULL;
    (data->select == 3) ?
        hud_keymap_button_activate(data->content.keymap_action.data, 1) : NULL;
    (data->select == 4) ?
        hud_keymap_button_activate(data->content.keymap_cancel.data, 1) : NULL;
    (data->select == 5) ?
        hud_keymap_button_activate(data->content.keymap_down.data, 1) : NULL;
    (data->select == 6) ?
        hud_keymap_button_activate(data->content.keymap_left.data, 1) : NULL;
    (data->select == 7) ?
        hud_keymap_button_activate(data->content.keymap_right.data, 1) : NULL;
    (data->select == 8) ?
        hud_keymap_button_activate(data->content.keymap_up.data, 1) : NULL;
}

void hud_menu_manage_mouse(dg_window_t *w, data_t *data)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(w->window);
    sfVector2f pos = {mouse_pos.x - 600, mouse_pos.y - 200};

    if (10 * 80 < pos.y || pos.y < 0
        || pos.x < 0 || pos.x > 1800 ||
        (mouse_pos.x == data->mouse_memory.x
        && mouse_pos.y == data->mouse_memory.y))
        return;
    data->mouse_memory.x = mouse_pos.x;
    data->mouse_memory.y = mouse_pos.y;
    for (int i = 0; i < 10; i++)
        if (pos.y < (80 * (i + 1))) {
            (i != data->select) ? sound_play(data->sound_move) : 0;
            data->select = i;
            return;
        }
}

void update_sound(data_t *data, general_data_t *gd)
{
    float gvm = gd->options.general_volume.x;

    if (data->gvm != gvm) {
        gd->options.music.x += gvm - data->gvm;
        gd->options.sound.x += gvm - data->gvm;
        data->gvm = gvm;
    }
    gd->options.music.x = (gd->options.music.x < 0) ? 0 : gd->options.music.x;
    gd->options.sound.x = (gd->options.sound.x < 0) ? 0 : gd->options.sound.x;
    gd->options.music.x = (gd->options.music.x > 100) ?
        100 : gd->options.music.x;
    gd->options.sound.x = (gd->options.sound.x > 100) ?
        100 : gd->options.sound.x;
}