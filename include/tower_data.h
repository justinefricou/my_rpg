/*
** EPITECH PROJECT, 2020
** tower_data
** File description:
** tower_data
*/

#ifndef TOWER_DATA_H_
#define TOWER_DATA_H_

typedef struct tower_data
{
    float radius;
    sfVector2f *pos;
    dg_entity_t *entity;
    sfCircleShape *circle;
    float delay_max;
    float delay;
    int id;
    int stat;
    dg_entity_t *buttons[2];
    dg_component_t *sheet;
} tower_data_t;

#endif /* !TOWER_DATA_H_ */