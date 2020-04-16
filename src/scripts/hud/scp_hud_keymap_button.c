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

typedef struct data {
    sfVector2f *pos;
    int size;
    int *keymap;
    int active;
    int change_key;
    sfText *text;
    sfVector2f *tpos;
    dg_entity_t *text_ent;
    sfMusic *sound_active;
} data_t;

void hud_keymap_button_activate(dg_entity_t *kb, int stat)
{
    script_t *script = (script_t *)dg_entity_get_component(kb, "script");
    data_t *data = script->data;

    data->active = stat;
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
    data->text = dg_entity_get_component(data->text_ent, "text");
    data->tpos = dg_entity_get_component(data->text_ent, "pos");
    data->sound_active = dg_ressources_get_audio_by_name("hud_activate");
    data->pos = pos->data;
    data->keymap = (int *)idata[3];
    data->size = *((int *)idata[2]);
    data->active = 0;
    data->change_key = 0;
    dg_scene_add_ent(scene, data->text_ent);
    dg_entity_add_component(entity, pos);
    return data;
}

void trash_call(void) {

}

static void hud_kb_active(dg_window_t *w, data_t *data)
{
    if (keymap_is_clicked(w, "action", 1)) {
        trash_call();
        sound_play(data->sound_active);
        data->change_key = 1;
        w->events.keyboard_pressed = -1;
    }
    if (data->change_key && w->events.keyboard_pressed != -1 
        && w->events.keyboard_pressed != *(data->keymap)
        && !is_keymap(w, w->events.keyboard_pressed)) {
        sound_play(data->sound_active);
        *(data->keymap) = w->events.keyboard_pressed;
        w->events.keyboard_pressed = -1;
        data->change_key = 0;
    }
}

void scp_hud_keymap_button_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;
    sfFloatRect ts =  sfText_getGlobalBounds(data->text);

    if (data->active)
        hud_kb_active(w, data);
    sfText_setString(data->text, keycode_to_text(*(data->keymap)));
    data->tpos->x = data->pos->x + ((data->size * 16 * 3) - ts.width) / 2;
    data->tpos->x -= ts.left;
}

void scp_hud_keymap_button_end(void *data)
{
    data_t *d = (data_t *)data;

    free(d);
}