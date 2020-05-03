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
#include "hud/hud_language_button.h"
#include "general_data.h"

static const sfColor BUTTON_ACTIVE = {255, 255, 255, 255};
static const sfColor BUTTON_DESACTIVE = {230, 230, 230, 255};

void hud_lang_button_activate(dg_entity_t *kb, int stat)
{
    script_t *script = (script_t *)dg_entity_get_component(kb, "script");
    data_t *data = script->data;

    data->active = stat;
}

void *scp_hud_language_button_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    dg_entity_t *entity = idata[0];
    sfVector2f *dpos = idata[1];
    dg_scene_t *scene = idata[4];
    dg_component_t *pos = dg_cpt_pos(dpos->x, dpos->y);
    dg_component_t *color = cpt_color(BUTTON_DESACTIVE);

    data->text_ent = ent_text(dpos->x + 30, dpos->y - 5, 40, "");
    data->pos = pos->data;
    dg_scene_add_ent(scene, data->text_ent);
    dg_entity_add_component(entity, pos);
    data->color = color->data;
    dg_entity_add_component(entity, color);
    data->text = dg_entity_get_component(data->text_ent, "text");
    data->tpos = dg_entity_get_component(data->text_ent, "pos");
    data->active = 0;
    data->sound_active = dg_ressources_get_audio_by_name("hud_activate");
    return data;
}

static void hud_lang_active(dg_window_t *w, data_t *data)
{
    general_data_t *gd = (general_data_t *)w->general_data;
    char *lang = 0;

    if (keymap_is_clicked(w, "action", 1)) {
        sound_play(data->sound_active);
        gd->options.language = gd->options.language != 1;
        lang = (gd->options.language) ? "fr" : "en";
        init_dialogs(&(gd->dialogs), lang);
    }
}

void scp_hud_language_button_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;
    general_data_t *gd = w->general_data;
    sfFloatRect ts =  sfText_getGlobalBounds(data->text);

    if (data->active) {
        *(data->color) = BUTTON_ACTIVE;
        hud_lang_active(w, data);
    } else
        *(data->color) = BUTTON_DESACTIVE;
    if (gd->options.language)
        sfText_setString(data->text, "Francais");
    else
        sfText_setString(data->text, "Anglais");
}

void scp_hud_language_button_end(void *data)
{
    data_t *d = (data_t *)data;

    free(d);
}