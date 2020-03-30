/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** Parsing of dialogs.
*/

#include <stdlib.h>
#include <string.h>
#include "init_dialogs.h"

static int init_dialogs_arrays(dialogs_t *dialogs, char *content)
{
    int nb_lines = 0;

    for (; *content; nb_lines += (*content == '\n'), content++);
    dialogs->ids = malloc(sizeof(char *) * (nb_lines + 1));
    if (dialogs->ids == NULL)
        return (84);
    dialogs->lines = malloc(sizeof(char *) * (nb_lines + 1));
    if (dialogs->lines == NULL) {
        free(dialogs->ids);
        return (84);
    }
    memset(dialogs->ids, 0, nb_lines + 1);
    memset(dialogs->lines, 0, nb_lines + 1);
    return (0);
}

static int add_elem_to_dialog(char **elem, char **content, int type)
{
    int len_elem = 0;
    char end = 0;

    end = type ? '\n' : ' ';
    for (; (*content)[len_elem] && (*content)[len_elem] != end; len_elem++);
    *elem = malloc(sizeof(char) * (len_elem + 1));
    if (*elem == NULL)
        return (84);
    for (int i = 0; **content && **content != end; (*content)++, i++)
        (*elem)[i] = **content;
    (*elem)[len_elem] = 0;
    (*content)++;
    return (0);
}

int parse_dialogs(dialogs_t *dialogs, char *content)
{
    if (init_dialogs_arrays(dialogs, content) == 84)
        return (84);
    for (int i = 0; *content; i++) {
        if (add_elem_to_dialog(&(dialogs->ids[i]), &content, 0) == 84 ||
            add_elem_to_dialog(&(dialogs->lines[i]), &content, 1) == 84) {
            free_string_array(dialogs->ids);
            free_string_array(dialogs->lines);
            return (84);
        }
    }
    return (0);
}

void free_string_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}