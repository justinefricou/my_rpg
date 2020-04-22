/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** map
*/

#include "libmy.h"
#include "libdragon.h"
#include "dirent.h"
#include "map.h"
#include "general_data.h"
#include <stdlib.h>

static int get_int(char *str)
{
    int nb = 0;
    int i = 0;
    int negate = 1;

    if (str[i] == '-') {
        i++;
        negate *= -1;
    }
    for (; str[i] >= '0' && str[i] <= '9'; i++) {
        nb *= 10;
        nb += str[i] - '0';
    }
    nb *= negate;
    return nb;
}

static void set_map(int ***map, char *content, int width, int height)
{
    int x = 0;
    int c = 0;
    int line_len = 0;
    int readed = 0;

    for (int y = 0; y < height; y++) {
        for (line_len = 0; content[readed + line_len] != '\n'; line_len++);
        x = 0;
        c = 0;
        while (x < width) {
            (*map)[y][x] = get_int(&(content[readed + c])) + 1;
            c += my_nblen((*map)[y][x]) + 1;
            c += ((*map)[y][x] <= 0) ? 1 : 0;
            x++;
        }
        readed += line_len + 1;
    }
}

int **create_map(char *content)
{
    int width = 1;
    int height = 0;
    int **map = NULL;

    for (int i = 0; content[i] != '\n'; i++)
        if (content[i] == ',')
            width++;
    for (int i = 0; content[i] != '\0'; i++)
        if (content[i] == '\n')
            height++;
    map = malloc(sizeof(int *) * (height + 1));
    for (int i = 0; i < height; i++) {
        map[i] = malloc(sizeof(int) * (width + 1));
        map[i][width] = -1;
    }
    map[height] = NULL;
    set_map(&map, content, width, height);
    return map;
}