/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** hud keymap button
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "hud/hud_keymap_button.h"

static const sfColor BUTTON_ACTIVE = {255, 255, 255, 255};
static const sfColor BUTTON_DESACTIVE = {230, 230, 230, 255};
static const sfColor BUTTON_CLICKED = {255, 200, 200, 255};

static void kb_set_data(data_t *data, dg_entity_t *entity)
{
    dg_component_t *color = cpt_color(BUTTON_DESACTIVE);

    data->color = color->data;
    dg_entity_add_component(entity, color);
    data->text = dg_entity_get_component(data->text_ent, "text");
    data->tpos = dg_entity_get_component(data->text_ent, "pos");
    data->active = 0;
    data->change_key = 0;
    data->sound_active = dg_ressources_get_audio_by_name("hud_activate");
}

void *scp_hud_keymap_button_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    dg_entity_t *entity = idata[0];
    sfVector2f *dpos = idata[1];
    dg_scene_t *scene = idata[4];
    dg_component_t *pos = dg_cpt_pos(dpos->x, dpos->y);

    data->text_ent = ent_text(dpos->x, dpos->y - 5, 40, "");
    data->pos = pos->data;
    data->keymap = (int *)idata[3];
    data->size = *((int *)idata[2]);
    dg_scene_add_ent(scene, data->text_ent);
    dg_entity_add_component(entity, pos);
    kb_set_data(data, entity);
    return data;
}

static void hud_kb_active(dg_window_t *w, data_t *data)
{
    general_data_t *gd = (general_data_t *)w->general_data;

    if (keymap_is_clicked(w, "action", 1)) {
        *(data->color) = BUTTON_CLICKED;
        sound_play(data->sound_active);
        data->change_key = 1;
        gd->block_input = 1;
        w->events.keyboard_pressed = -1;
    }
    if (data->change_key && w->events.keyboard_pressed != -1
        && (w->events.keyboard_pressed == *(data->keymap)
        || !is_keymap(w, w->events.keyboard_pressed))) {
        sound_play(data->sound_active);
        *(data->keymap) = w->events.keyboard_pressed;
        w->events.keyboard_pressed = -1;
        data->change_key = 0;
        gd->block_input = 0;
    }
}

void scp_hud_keymap_button_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;
    sfFloatRect ts =  sfText_getGlobalBounds(data->text);

    if (data->active) {
        *(data->color) = BUTTON_ACTIVE;
        hud_kb_active(w, data);
    } else
        *(data->color) = BUTTON_DESACTIVE;
    if (data->change_key)
        *(data->color) = BUTTON_CLICKED;
    sfText_setString(data->text, keycode_to_text(*(data->keymap)));
    data->tpos->x = data->pos->x + ((data->size * 16 * 3) - ts.width) / 2;
    data->tpos->x -= ts.left;
}

void scp_hud_keymap_button_end(void *data)
{
    data_t *d = (data_t *)data;

    free(d);
}