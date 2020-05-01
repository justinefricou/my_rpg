/*
** EPITECH PROJECT, 2020
** background_menu
** File description:
** background_menu
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "libmy.h"
#include "general_data.h"
#include "instructions.h"
#include "script_event_data.h"
#include "epitech_tools.h"
#include "tilemap.h"

void move_set_animation(sfVector2f move, dg_animator_t *mator)
{
    char *anim = "idle";

    anim = (move.x > 0) ? "right" : anim;
    anim = (move.x < 0) ? "left" : anim;
    anim = (move.y > 0) ? "down" : anim;
    anim = (move.y < 0) ? "up" : anim;
    dg_animator_set_animation(mator, anim);
}

sfVector2f *set_move_target(self_data_t self,
    general_data_t *gd, parameters_t *params, dg_animator_t **mator)
{
    dg_scene_t *scene = dg_scene_manager_get_scene("layer_event");
    dg_entity_t *player = dg_get_entity(scene->entities, "player");
    sfVector2f *pos = NULL;

    if (!dg_strcmp("PLAYER", params[0].parameters.s)) {
         pos = dg_entity_get_component(player, "pos");
         gd->lock.menu = 1;
         gd->lock.move = 1;
         *mator = dg_entity_get_component(player, "animator");
    } else if (!dg_strcmp("SELF", params[0].parameters.s)) {
        pos = self.pos;
        *mator = self.animator;
    } else {
        player = dg_get_entity(scene->entities, params[0].parameters.s);
        pos = dg_entity_get_component(player, "pos");
        *mator = dg_entity_get_component(player, "animator");
    }
    return pos;
}

void move_set_collision(sfVector2f *pos, dg_window_t *w)
{
    dg_scene_t *scene = dg_scene_manager_get_scene("layer_event");
    dg_entity_t *ent_map = dg_get_entity(scene->entities, "map");
    tilemap_t *tm = dg_entity_get_component(ent_map, "tilecollide");
    sfVector2f e_pos = {(pos->x + 24) / (16 * 3),
        (pos->y + 24) / (16 * 3)};

    if ((int)e_pos.y < 0 || (int)e_pos.x < 0 ||
        (int)e_pos.y > tm->height || (int)e_pos.x > tm->width)
        return;
    tm->map[(int)e_pos.y][(int)e_pos.x] = 0;
}

sfVector2f move_set_move(sfVector2f *pos, sfVector2f target)
{
    sfVector2f move = {0};

    move.x = (pos->x - 2 > target.x) ? -1 : move.x;
    move.x = (pos->x + 2 < target.x) ? 1 : move.x;
    move.y = (pos->y - 2 > target.y) ? -1 : move.y;
    move.y = (pos->y + 2 < target.y) ? 1 : move.y;
    if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
        move.x *= 3;
        move.y *= 3;
    }
    return move;
}