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

typedef struct map_data {
    char *name;
    int width;
    int height;
    map_layer_t layers;
} map_data_t;

int open_file(char *filename, int *fd);
int get_map_content(char **content, int fd);
char *set_path(char *filename, char letter);
int **create_map(char *content);

#endif /*MAP_H_*/
