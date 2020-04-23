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

static void set_path_begin(char *filename)
{
    char *begin = "res/events/";

    for (int i = 0; i < 11; i++) {
        filename[i] = begin[i];
    }
}

char *set_event_path(char *filename)
{
    int fn_len = my_strlen(filename);
    char *path = malloc(sizeof(char) * (fn_len + 12));

    set_path_begin(path);
    for (int i = 0; filename[i]; i++)
        path[i + 11] = filename[i];
    path[fn_len + 11] = 0;
    return path;
}