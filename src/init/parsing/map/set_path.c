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
    char *begin = "res/map/";

    for (int i = 0; i < 8; i++) {
        filename[i] = begin[i];
    }
}

char *set_path(char *filename, char letter)
{
    int fn_len = my_strlen(filename);
    char *path = malloc(sizeof(char) * (fn_len + 15));

    set_path_begin(path);
    for (int i = 0; filename[i]; i++)
        path[i + 8] = filename[i];
    path[fn_len + 8] = '/';
    path[fn_len + 9] = letter;
    path[fn_len + 10] = '.';
    path[fn_len + 11] = 'c';
    path[fn_len + 12] = 's';
    path[fn_len + 13] = 'v';
    path[fn_len + 14] = 0;
    return path;
}