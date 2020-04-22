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

char *set_mev_path(char *filename)
{
    int filelen = my_strlen(filename);
    char *filepath = malloc(sizeof(char) * (filelen + 16));
    const char *b_path = "res/map/";
    const char *a_path = "/events";

    for (int i = 0; i < 8; i++)
        filepath[i] = b_path[i];
    for (int i = 0; i < filelen; i++)
        filepath[i + 8] = filename[i];
    for (int i = 0; i < 7; i++)
        filepath[i + 8 + filelen] = a_path[i];
    filepath[filelen + 15] = '\0';
    return filepath;
}

char *parse_mev_data(char **content)
{
    char *copy = *content;
    char *result = NULL;
    int len = 0;

    for (; copy[len] != ' ' && copy[len] != '\n'
        && copy[len] != '\0'; len++);
    result = malloc(sizeof(char) * (len + 1));
    for (int j = 0; j < len; j++) {
        result[j] = copy[j];
    }
    result[len] = 0;
    *content = &((*content)[len]);
    return result;
}

int mev_data_int(char **content)
{
    char *str = parse_mev_data(content);
    int result = 0;

    result = my_atoi(*content) - 1;
    return result;
}

map_events_t add_mev(char **content)
{
    map_events_t ev = {0};

    ev.name = parse_mev_data(content);
    *content = &((*content)[1]);
    ev.interaction = mev_data_int(content);
    *content = &((*content)[1]);
    ev.pos.x = mev_data_int(content);
    *content = &((*content)[1]);
    ev.pos.y = mev_data_int(content);
    *content = &((*content)[1]);
    ev.animator_id = mev_data_int(content);
    if (**content)
        *content = &((*content)[1]);
    return ev;
}

map_events_t *create_mev_list(char *content, int *ev_len)
{
    map_events_t *ev = malloc(sizeof(map_events_t));
    map_events_t *tmp = NULL;
    
    while (*content) {
        tmp = malloc(sizeof(map_events_t) * (*ev_len + 2));
        for (int c = 0; c < *ev_len; c++)
            tmp[c] = ev[c];
        tmp[*ev_len] = add_mev(&content);
        tmp[*ev_len + 1].name = NULL;
        free(ev);
        ev = tmp;
        *ev_len += 1;
    }
    return ev;
}

map_events_t *get_map_events(char *filename, int *ev_len)
{
    int fd = 0;
    map_events_t *ev = NULL;
    char *content = NULL;
    char *name = set_mev_path(filename);

    *ev_len = 0;
    if (open_file(name, &fd) == 84)
        return NULL;
    if (get_map_content(&content, fd) == 84) {
        close(fd);
        return NULL;
    }
    close(fd);
    ev = create_mev_list(content, ev_len);
    free(content);
    return ev;
}