/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** script player controller
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "tilemap.h"
#include "general_data.h"
#include "epitech_tools.h"
#include "event.h"
#include "instructions.h"
#include "script_event_data.h"

void event_active(intern_t *data, self_data_t self, dg_window_t *w, sfTime dt)
{
    if (!data->reader.active)
        return;
    while (data->script[data->reader.progress].keycode != NONE &&
        key_active[data->script[data->reader.progress].keycode]
        (data, self, w, dt)) {
        update_special_variable(w->general_data);
        key_end[data->script[data->reader.progress].keycode](data);
        data->reader.progress++;
        if (data->script[data->reader.progress].keycode != NONE) {
            data->intern =
                key_init[data->script[data->reader.progress].keycode]
                (data, w->general_data);
        }
    }
    if (data->script[data->reader.progress].keycode == NONE) {
        data->reader.active = 0;
    }
}

void event_launch(intern_t *data, general_data_t *gd)
{
    if (data->reader.activation) {
        data->reader.progress = 0;
        data->reader.active = 1;
        data->reader.activation = 0;
        data->reader.end = 0;
        if (data->script[data->reader.progress].keycode != NONE)
            data->intern =
                key_init[data->script[data->reader.progress].keycode]
                (data, gd);
    }
}

void check_interaction(data_t *data, dg_array_t **entities, dg_window_t *w)
{
    dg_entity_t *player = dg_get_entity(*entities, "player");
    sfVector2f *pos = dg_entity_get_component(player, "pos");
    sfVector2f p_pos = {pos->x / (16 * 3), pos->y / (16 * 3)};
    sfVector2f e_pos = {data->self.pos->x / (16 * 3),
        data->self.pos->y / (16 * 3)};

    if (keymap_is_clicked(w, "action", 0)) {
        if (p_pos.x - 1.5 <= e_pos.x && p_pos.x + 1.5 >= e_pos.x
            && p_pos.y - 1.5 <= e_pos.y && p_pos.y + 1.5 >= e_pos.y &&
            data->intern.reader.active == 0) {
                data->intern.reader.activation = 1;
                data->intern.reader.progress = 0;
        }
    }
}

void set_collision(data_t *data, dg_array_t **entities, dg_window_t *w)
{
    dg_entity_t *ent_map = dg_get_entity(*entities, "map");
    tilemap_t *tm = dg_entity_get_component(ent_map, "tilecollide");
    sfVector2f e_pos = {(data->self.pos->x + 24) / (16 * 3),
        (data->self.pos->y + 24) / (16 * 3)};

    if ((int)e_pos.y < 0 || (int)e_pos.x < 0 ||
        (int)e_pos.y >= tm->height || (int)e_pos.x >= tm->width)
        return;
    tm->map[(int)e_pos.y][(int)e_pos.x] = 1;
    if (data->self.pos->x != data->self.memory.x
        || data->self.pos->y != data->self.memory.y) {
            tm->map[(int)(data->self.memory.y / (16 * 3))]
            [(int)(data->self.memory.y / (16 * 3))] = 0;
            data->self.memory.x = data->self.pos->x;
            data->self.memory.y = data->self.pos->y;
    }
}

void update_special_variable(general_data_t *gd)
{
    gd->event_manager.var[variable_to_int("PV", gd)].data = gd->player.pv.x;
    gd->event_manager.var[variable_to_int("PV_MAX", gd)].data =
        gd->player.pv.y;
    gd->event_manager.var[variable_to_int("PM", gd)].data =
        gd->player.pm.x;
    gd->event_manager.var[variable_to_int("XP", gd)].data =
        gd->player.xp.x;
    gd->event_manager.var[variable_to_int("LEVEL", gd)].data =
        gd->player.level;
    gd->event_manager.var[variable_to_int("PM_MAX", gd)].data =
        gd->player.pm.x;
    gd->event_manager.var[variable_to_int("MONEY", gd)].data =
        gd->player.money;
    gd->event_manager.var[variable_to_int("WEIGHT", gd)].data =
        gd->inventory.stack.x;
    gd->event_manager.var[variable_to_int("WEIGHT_MAX", gd)].data =
        gd->inventory.stack.y;
}