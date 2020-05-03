/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** Opening and reading
*/

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libmy.h"
#include "libdragon.h"
#include "map.h"
#include "general_data.h"

int open_file(char *filename, int *fd)
{
    *fd = open(filename, O_RDONLY);
    free(filename);
    if (*fd == -1)
        return (84);
    return (0);
}

int get_map_content(char **content, int fd)
{
    struct stat buffer;
    int size_of_read = 0;

    if (fstat(fd, &buffer) == -1)
        return (84);
    *content = malloc(sizeof(char) * buffer.st_size + 1);
    if (*content == NULL)
        return (84);
    size_of_read = read(fd, *content, buffer.st_size);
    if (size_of_read != buffer.st_size)
        return (84);
    (*content)[buffer.st_size] = 0;
    return (0);
}

int mev_data_int(char **content)
{
    char *str = parse_mev_data(content);
    int result = get_int(str);

    free(str);
    return result;
}