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

char *copy(char *source)
{
    int len = my_strlen(source);
    char *cop = malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len; i++)
        cop[i] = source[i];
    cop[len] = '\0';
    return cop;
}

void destroy_map_list(map_t map_list)
{
    int **map = 0;

    for (int i = 0; i < map_list.len; i++) {
        map = map_list.map[i].layers.bottom;
        map ? free(map) : NULL;
        map = map_list.map[i].layers.bottom_hover;
        map ? free(map) : NULL;
        map = map_list.map[i].layers.event;
        map ? free(map) : NULL;
        map = map_list.map[i].layers.hover;
        map ? free(map) : NULL;
        map = map_list.map[i].layers.middle;
        map ? free(map) : NULL;
    }
    free(map_list.map);
}

int **get_map(char *filename, char letter)
{
    int fd = 0;
    int **map = NULL;
    char *content = NULL;
    char *name = set_path(filename, letter);

    if (open_file(name, &fd) == 84)
        return NULL;
    if (get_map_content(&content, fd) == 84) {
        close(fd);
        return NULL;
    }
    close(fd);
    map = create_map(content);
    free(content);
    return map;
}

void set_whole_map(map_t *map_list, char *filename)
{
    map_data_t *new = malloc(sizeof(map_data_t) * (map_list->len + 1));

    for (int i = 0; i < map_list->len; i++)
        new[i] = map_list->map[i];
    new[map_list->len].name = copy(filename);
    new[map_list->len].layers.bottom = get_map(filename, '0');
    new[map_list->len].layers.bottom_hover = get_map(filename, '1');
    new[map_list->len].layers.middle = get_map(filename, '2');
    new[map_list->len].layers.hover = get_map(filename, '3');
    new[map_list->len].layers.event = get_map(filename, 'c');
    new[map_list->len].events = get_map_events(filename,
        &(new[map_list->len].events_len));
    map_list->len += 1;
    free(map_list->map);
    map_list->map = new;
}

map_t set_map_data(void)
{
    DIR *directory = NULL;
    struct dirent *current_file = NULL;
    map_t map_list = {0, NULL};

    directory = opendir("res/map/");
    if (directory == NULL)
        return map_list;
    do {
        current_file = readdir(directory);
        if (current_file == NULL || current_file->d_type != DT_DIR)
            continue;
        if (current_file->d_name[0] == '.')
            continue;
        set_whole_map(&map_list, current_file->d_name);
    } while (current_file != NULL);
    closedir(directory);
    return map_list;
}