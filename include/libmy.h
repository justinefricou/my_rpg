/*
** EPITECH PROJECT, 2020
** libmy.h
** File description:
** All lib functions
*/

#ifndef _LIBMY_H_
#define _LIBMY_H_

#ifndef READ_SIZE
#define READ_SIZE (3)
#endif /* READ_SIZE */

typedef struct val {
    char *buff_inter;
    int turn;
    int carac;
} val_t;

// get_next_line.c
char *get_next_line(int fd);

// my_putarray.c
void my_putarray(char **tab, char last_char);

// my_strcpy.c
char *my_strcpy(char *dest, char *src);

// str_to_array.c
char **str_to_array(char *str, char c);

// tools_function.c
void my_putchar(char c);

int my_putnbr(int nb);
int my_putstr(char const *str);
int my_strcmpp(char const *s1, char const *s2);

char *my_len_str(char *str);

//transform_character.c
int my_atoi(char *str);
int my_strlen(char const *str);

// my_strdup.c
char *my_strdup(char *src);

// my_itoa.c
char *my_itoa(int nb);

// my_revstr
char *my_revstr(char *str);

// my_nblen
int my_nblen(int nb);

#endif