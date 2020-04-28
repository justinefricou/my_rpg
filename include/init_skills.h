/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Skills initialization and parsing : header
*/

#ifndef DEF_INIT_SKILLS_H
#define DEF_INIT_SKILLS_H

// skills.c
void destroy_skills_array(skill_t *skills);
skill_t *init_skills(char *language);

// parse_skills.c
int parse_skills(skill_t *skills, FILE *res_file, int nb_skills);

#endif /* !DEF_INIT_SKILLS_H */