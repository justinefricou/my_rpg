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

void event_active(intern_t *data, self_data_t self, dg_window_t *w)
{
    if (!data->reader.active)
        return;
    while (data->script[data->reader.progress].keycode != NONE &&
        key_active[data->script[data->reader.progress].keycode]
        (data, self, w)) {
        key_end[data->script[data->reader.progress].keycode](data);
        data->reader.progress++;
        if (data->script[data->reader.progress].keycode != NONE) {
            data->intern =
                key_init[data->script[data->reader.progress].keycode](data);
        }
    }
    if (data->script[data->reader.progress].keycode == NONE) {
        data->reader.active = 0;
    }
}

void event_launch(intern_t *data)
{
    if (data->reader.activation) {
        data->reader.progress = 0;
        data->reader.active = 1;
        data->reader.activation = 0;
        data->reader.end = 0;
        if (data->script[data->reader.progress].keycode != NONE)
            data->intern =
                key_init[data->script[data->reader.progress].keycode](data);
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
        if (p_pos.x - 1 <= e_pos.x && p_pos.x + 1 >= e_pos.x
            && p_pos.y - 1 <= e_pos.y && p_pos.y + 1 >= e_pos.y) {
                data->intern.reader.activation = 1;
                data->intern.reader.progress = 0;
        }
    }
}

void set_collision(data_t *data, dg_array_t **entities, dg_window_t *w)
{
    dg_entity_t *ent_map = dg_get_entity(*entities, "map");
    tilemap_t *tm = dg_entity_get_component(ent_map, "tilecollide");
    sfVector2f e_pos = {data->self.pos->x / (16 * 3),
        data->self.pos->y / (16 * 3)};

    tm->map[(int)e_pos.y][(int)e_pos.x] = 1;
    if (data->self.pos->x != data->self.memory.x
        || data->self.pos->y != data->self.memory.y) {
            tm->map[(int)(data->self.memory.y / (16 * 3))]
            [(int)(data->self.memory.y / (16 * 3))] = 0;
            data->self.memory.x = data->self.pos->x;
            data->self.memory.y = data->self.pos->y;
    }
}