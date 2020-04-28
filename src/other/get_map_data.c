/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** map
*/

#include <dirent.h>
#include <sys/types.h>
#include "libmy.h"
#include "libdragon.h"
#include "map.h"
#include "general_data.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "epitech_tools.h"

map_data_t get_map_data(char *name, general_data_t *gd)
{
    for (int i = 0; i < gd->maps.len; i++) {
        if (!dg_strcmp(name, gd->maps.map[i].name))
            return gd->maps.map[i];
    }
    return gd->maps.map[0];
}