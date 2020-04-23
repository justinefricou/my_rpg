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
#include "instructions.h"
#include "general_data.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void destroy_events_list(event_t *event_list)
{
    for (int i = 0; event_list->parameters[i].parameters; i++) {
        free(event_list->parameters[i].parameters);
    }
    free(event_list->parameters);
    free(event_list);
}

instruction_t *set_parameters(char *filename, int *len)
{
    int fd = 0;
    instruction_t *ins = NULL;
    char *content = NULL;
    char *name = set_event_path(filename);

    if (open_event_file(name, &fd) == 84)
        return NULL;
    if (get_event_content(&content, fd) == 84) {
        close(fd);
        return NULL;
    }
    close(fd);
    ins = create_event(content, len);
    free(content);
    return ins;
}

static char *copy_name(char *name)
{
    int len = my_strlen(name);
    char *result = malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len; i++)
        result[i] = name[i];
    result[len] = '\0';
    return result;
}

void add_event(event_t **event_list, char *filename, int *len)
{
    event_t *new = malloc(sizeof(event_t) * (*len + 2));

    for (int i = 0; i < *len; i++)
        new[i] = (*event_list)[i];
    new[*len].name = copy_name(filename);
    new[*len].len = 0;
    new[*len].parameters = set_parameters(filename, &(new[*len].len));
    *len += 1;
    new[*len].parameters = NULL;
    new[*len].len = 0;
    new[*len].name = 0;
    *event_list = new;
}    

event_t *set_text_events(void)
{
    DIR *directory = NULL;
    struct dirent *current_file = NULL;
    event_t *events_list = {0};
    int len = 0;

    directory = opendir("res/events/");
    if (directory == NULL)
        return events_list;
    do {
        current_file = readdir(directory);
        if (current_file == NULL || current_file->d_type != DT_REG)
            continue;
        if (current_file->d_name[0] == '.')
            continue;
        add_event(&events_list, current_file->d_name, &len);
    } while (current_file != NULL);
    closedir(directory);
    return events_list;
}