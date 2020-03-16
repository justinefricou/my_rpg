/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** script structure
*/

#include "libdragon.h"
#include "tower_data.h"

#ifndef SCRIPT_H_
#define SCRIPT_H_

typedef struct script
{
    void *(*init)(void *);
    dg_sysf_t loop;
    void (*end)(void *);
    void *data;
} script_t;

/*
// build menu
void *scp_build_menu_init(void *init_data);
void scp_build_menu_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void scp_build_menu_end(void *data);
*/

#endif /*SCRIPT_H_*/
