/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** dialog_parsing : header
*/

#ifndef DEF_DIALOG_PARSING
#define DEF_DIALOG_PARSING

typedef struct dialogs {
    char **ids;
    char **lines;
} dialogs_t;

// init_dialogs.c
int init_dialogs(dialogs_t *dialogs);
void destroy_dialogs(dialogs_t dialogs);
int get_dialog_id(char *str, dialogs_t dialogs);

// pars_dialogs.c
int parse_dialogs(dialogs_t *dialogs, char *content);
void free_string_array(char **array);

#endif // DEF_DIALOG_PARSING