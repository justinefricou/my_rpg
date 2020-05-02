/*
** EPITECH PROJECT, 2020
** libmy.h
** File description:
** All lib functions
*/

#ifndef _MATOR_H_
#define _MATOR_H_

#include "libdragon.h"

//size : 12 + 4

//characters
//main
dg_animator_t *mator_pdg(void);
dg_animator_t *mator_camping(void);
dg_animator_t *mator_librarian(void);
dg_animator_t *mator_policeman(void);
dg_animator_t *mator_photograph(void);
dg_animator_t *mator_cashier(void);
//side
dg_animator_t *mator_mother_one(void);
dg_animator_t *mator_mother(void);
dg_animator_t *mator_child_two(void);
dg_animator_t *mator_child_one(void);
dg_animator_t *mator_child(void);

//obj
dg_animator_t *mator_dead(void);

#endif