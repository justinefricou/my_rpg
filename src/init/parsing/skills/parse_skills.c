/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Parsing of the skills : name, description and type.
*/

#include <stdlib.h>
#include <unistd.h>
#include "libmy.h"
#include "general_data.h"
#include "save_load.h"

static int set_skill_type(skill_t *skill, char **line)
{
    char *types[4] = {"INTIMIDATION", "FLATTERY", "TRICKERY", "REPARTEE"};
    int len = 0;
    int type_found = 0;

    for (; (*line)[len] && (*line)[len] != ' '; len++);
    if ((*line)[len] == 0)
        return (84);
    (*line)[len] = 0;
    for (int i = 0; i < 4; i++) {
        if (!my_strcmpp(*line, types[i])) {
            skill->type = i;
            type_found = 1;
        }
    }
    *line += len + 1;
    if (!type_found)
        write(2, "Error : Incorrect skill type.\n", 30);
    return (type_found ? 0 : 84);
}

static int set_skill_name(skill_t *skill, char **line)
{
    char *name = NULL;
    int len = 0;

    if (**line != '"')
        return (84);
    for (; (*line)[len + 1] && (*line)[len + 1] != '"'; len++);
    if ((*line)[len + 1] != '"' || (*line)[len + 2] != ' ')
        return (84);
    name = malloc(sizeof(char) * (len + 1));
    if (!name)
        return (84);
    for (int i = 0; i < len; i++)
        name[i] = (*line)[i + 1];
    name[len] = 0;
    skill->name = name;
    *line += len + 3;
    return (0);
}

static int set_skill_description(skill_t *skill, char *line)
{
    char *description = NULL;
    int len = 0;

    if (*line != '"')
        return (84);
    for (; line[len + 1] && line[len + 1] != '"'; len++);
    if (line[len + 1] != '"')
        return (84);
    description = malloc(sizeof(char) * (len + 1));
    if (!description)
        return (84);
    for (int i = 0; i < len; i++)
        description[i] = line[i + 1];
    description[len] = 0;
    skill->description = description;
    return (0);
}

static int init_skill(skill_t *skill, char *line)
{
    if (set_skill_type(skill, &line) == 84)
        return (84);
    if (set_skill_name(skill, &line) == 84)
        return (84);
    if (set_skill_description(skill, line) == 84) {
        free(skill->name);
        return (84);
    }
    return (0);
}

int parse_skills(skill_t *skills, FILE *res_file, int nb_skills)
{
    char *line = NULL;

    for (int i = 0; i < nb_skills; i++) {
        line = get_line_from_save_file(res_file);
        if (!line) {
            write(2, "Error : skill could not be read.\n", 33);
            return (84);
        } else if (init_skill(&(skills[i]), line) == 84) {
            write(2, "Error : Incorrect line in skills file.\n", 39);
            free(line);
            return (84);
        }
        free(line);
    }
    return (0);
}