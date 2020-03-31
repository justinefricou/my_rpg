/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Parsing of files containing the dialogs
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "libmy.h"
#include "init_dialogs.h"

static int open_dialog_file(char *language)
{
    char *filepath = NULL;
    int fd = 0;

    filepath = my_strcat("dialogs/dialogs_", language);
    if (!filepath)
        return (-1);
    fd = open(filepath, O_RDONLY);
    free(filepath);
    return (fd);
}

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

int init_dialogs(dialogs_t *dialogs, char *language)
{
    int fd = 0;
    char *content = NULL;

    fd = open_dialog_file(language);
    if (fd == -1)
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

void destroy_dialogs(dialogs_t dialogs)
{
    free_string_array(dialogs.ids);
    free_string_array(dialogs.lines);
}

int get_dialog_id(char *str, dialogs_t dialogs)
{
    for (int i = 0; dialogs.ids[i]; i++) {
        if (!my_strcmpp(str, dialogs.ids[i]))
            return (i);
    }
    return (-1);
}