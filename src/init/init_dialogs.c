/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Parsing of files containing the dialogs
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include "init_dialogs.h"

static int get_file_content(char **content, int fd)
{
    struct stat buffer;
    int size_of_read = 0;

    if (fstat(fd, &buffer) == -1)
        return (84);
    *content = malloc(sizeof(char) * buffer.st_size + 1);
    if (*content == NULL)
        return (84);
    size_of_read = read(fd, *content, buffer.st_size);
    if (size_of_read != buffer.st_size) {
        free(content);
        return (84);
    }
    (*content)[buffer.st_size] = 0;
    return (0);
}

int init_dialogs(dialogs_t *dialogs)
{
    char *content = NULL;
    int fd = 0;

    if ((fd = open("dialogs/dialog_test", O_RDONLY)) == -1)
        return (84);
    if (get_file_content(&content, fd) == 84) {
        close(fd);
        return (84);
    }
    close(fd);
    if (parse_dialogs(dialogs, content) == 84) {
        free(content);
        return (84);
    }
    free(content);
    return (0);
}

void destroy_dialogs(dialogs_t *dialogs)
{
    free_string_array(dialogs->ids);
    free_string_array(dialogs->lines);
    free(dialogs);
}