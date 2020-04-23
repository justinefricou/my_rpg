/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

typedef struct map_layer {
    int **bottom;
    int **bottom_hover;
    int **event;
    int **middle;
    int **hover;
} map_layer_t;

typedef struct map_events {
    char *name;
    int animator_id;
    sfVector2f pos;
    int interaction;
} map_events_t;

typedef struct map_data {
    char *name;
    int width;
    int height;
    map_layer_t layers;
    int events_len;
    map_events_t *events;
} map_data_t;

int open_file(char *filename, int *fd);
int get_map_content(char **content, int fd);
char *set_path(char *filename, char letter);
map_events_t *get_map_events(char *filename, int *ev_len);
int **create_map(char *content);
int get_int(char *str);

#endif /*MAP_H_*/
