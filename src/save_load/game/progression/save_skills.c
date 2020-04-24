/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Saves the skills' status (locked or unlocked).
*/

#include <stdio.h>
#include "save_load.h"

void save_skills(skill_t *skills, FILE *save_file)
{
    char unlocked[2] = {0};

    write_str_in_save_file("skills ", save_file);
    for (int i = 0; skills[i].name; i++) {
        unlocked[0] = skills[i].unlocked + '0';
        fwrite(unlocked, sizeof(char), 2, save_file);
    }
    fwrite("\n", sizeof(char), 1, save_file);
}