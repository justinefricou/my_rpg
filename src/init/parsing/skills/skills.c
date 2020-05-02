/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Init and destroy for skills.
*/

#include <stdlib.h>
#include <unistd.h>
#include "libmy.h"
#include "general_data.h"
#include "save_load.h"
#include "init_skills.h"

static void add_line_breaks(skill_t *skills)
{
    char c = 0;

    for (int i = 0; skills[i].description; i++) {
        for (int j = 0; skills[i].description[j]; j++) {
            c = skills[i].description[j];
            skills[i].description[j] = (c == '_') ? '\n' : c;
        }
    }
}

static FILE *open_skill_file(char *language)
{
    char *filepath = NULL;
    FILE *res_file = NULL;

    filepath = my_strcat("res/skills/skills_", language);
    if (!filepath)
        return (NULL);
    res_file = fopen(filepath, "r");
    if (!res_file)
        write(2, "Error : could not open skills file.\n", 36);
    return (res_file);
}

static skill_t *create_blank_skills_array(FILE *res_file, int *nb_skills)
{
    skill_t *skills = NULL;
    char *line = NULL;

    line = get_line_from_save_file(res_file);
    if (!line) {
        write(2, "Error : skills number could not be read.\n", 41);
        return (NULL);
    }
    *nb_skills = get_nbr_until(line, 0);
    free(line);
    if (*nb_skills <= 0)
        return (NULL);
    skills = malloc(sizeof(skill_t) * (*nb_skills + 1));
    for (int i = 0; i <= *nb_skills; i++) {
        skills[i].name = 0;
        skills[i].description = 0;
        skills[i].type = 0;
    }
    return (skills);
}

void destroy_skills_array(skill_t *skills)
{
    if (!skills)
        return;
    for (int i = 0; skills[i].name; i++) {
        free(skills[i].name);
        free(skills[i].description);
    }
    free(skills);
}

skill_t *init_skills(char *language)
{
    skill_t *skills = NULL;
    FILE *res_file = NULL;
    int nb_skills = 0;

    res_file = open_skill_file(language);
    if (!res_file)
        return (NULL);
    skills = create_blank_skills_array(res_file, &nb_skills);
    if (skills) {
        if (parse_skills(skills, res_file, nb_skills) == 84) {
            destroy_skills_array(skills);
            skills = NULL;
        }
    }
    fclose(res_file);
    add_line_breaks(skills);
    return (skills);
}