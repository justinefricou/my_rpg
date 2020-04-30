/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** objects
*/

#ifndef GIVE_H_
#define GIVE_H_

#include "libdragon.h"
#include "general_data.h"
#include "event.h"

//give
int give_obj(general_data_t *gd, parameters_t *params, int mul);
int give_player(general_data_t *gd, parameters_t *params, int mul);

//calcul
int event_calculate(parameters_t *params, general_data_t *gd, int len);

//move
void move_set_animation(sfVector2f move, dg_animator_t *);
sfVector2f *set_move_target(self_data_t self,
    general_data_t *gd, parameters_t *params, dg_animator_t **);
sfVector2f move_set_move(sfVector2f *pos, sfVector2f target);
void move_set_collision(self_data_t self, dg_window_t *w);

#endif /*GIVE_H_*/
