/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** main
*/

#include "libdragon.h"
#include "ecs.h"
#include "general_data.h"

int add_to_inventory(general_data_t *gd, int id, int nb)
{
    if (gd->inventory.stack.x + nb > gd->inventory.stack.y)
        return gd->inventory.stack.x + nb - gd->inventory.stack.y;
    for (int i = 0; i < gd->inventory.len; i++) {
        if (gd->inventory.slot[i].id == id) {
            gd->inventory.slot[i].nb += nb;
            gd->inventory.stack.x += nb;
            return 0;
        }
    }
    if (gd->inventory.len >= 100)
        return -1;
    gd->inventory.slot[gd->inventory.len].id = id;
    gd->inventory.slot[gd->inventory.len].nb = nb;
    gd->inventory.len++;
    gd->inventory.stack.x += nb;
    return 0;
}

static int rmfi(general_data_t *gd, int i, int nb)
{
    if (gd->inventory.slot[i].nb < nb)
        return nb - gd->inventory.slot[i].nb;
    gd->inventory.slot[i].nb -= nb;
    gd->inventory.stack.x -= nb;
    return 0;
}

int remove_from_inventory(general_data_t *gd, int id, int nb)
{
    for (int i = 0; i < gd->inventory.len; i++)
        if (gd->inventory.slot[i].id == id)
            return rmfi(gd, i, nb);
    return -1;
}

int is_in_inventory(general_data_t *gd, int id, int nb)
{
    for (int i = 0; i < gd->inventory.len; i++)
        if (gd->inventory.slot[i].id == id
            && gd->inventory.slot[i].nb >= nb)
            return 1;
    return 0;
}

int how_much_in_inventory(general_data_t *gd, int id)
{
    for (int i = 0; i < gd->inventory.len; i++)
        if (gd->inventory.slot[i].id == id)
            return gd->inventory.slot[i].nb;
    return 0;
}