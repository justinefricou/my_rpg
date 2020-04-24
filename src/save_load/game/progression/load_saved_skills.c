/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Loads the saved the skills' status (locked or unlocked).
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libmy.h"
#include "save_load.h"

int load_saved_skills(skill_t *skills, FILE *save_file)
{
    char *line = NULL;
    int start = 0;

    line = get_line_from_save_file(save_file);
    if (!line) {
        write(2, "Error : saved skills could not be loaded.\n", 42);
        return (84);
    }
    start = my_strlen("skills ");
    for (int i = 0; i < my_strlen(line) - start; i++) {
        if (!(skills[i].name)) {
            write(2, "Error : too many skills found in save file.\n", 44);
            return (84);
        }
        skills[i].unlocked = line[i + start] - '0';
    }
    free(line);
}