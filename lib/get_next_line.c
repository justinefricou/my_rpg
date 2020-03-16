/*
** EPITECH PROJECT, 2019
** getnextline
** File description:
** getnextline
*/

#include <stdlib.h>
#include <unistd.h>
#include "libmy.h"

char *read_next_n_bytes(int fd, int n, int count_run, char *buff)
{
    char *buff_count = malloc(sizeof(char) * 10000);
    char *buff_inter = malloc(sizeof(char) * n + 1);
    int op = 0, i = 0, j = 0;

    op = read(fd, buff_inter, n);
    buff_inter[n] = '\0';
    if (count_run == 1) {
        if (buff == NULL)
            return NULL;
        for (i = 0; buff[i] != '\n'; i++);
        for (j = 0, i++; buff[i] != '\0'; i++, j++)
            buff_count[j] = buff[i];
        for (int p = 0; buff_inter[p] != '\0'; j++, p++)
            buff_count[j] = buff_inter[p];
        buff_count[j] = '\0';
        return (buff_count);
    }
    if (op <= 0)
        return (NULL);
    return (buff_inter);
}

int read_and_display_read_line_n(char *buff, val_t *val)
{
    int i = 0;
    int turn_val = 0;

    for (; buff[i] != '\0'; i++)
        if (buff[i] == '\n') {
            turn_val++;
            break;
        }
    if (turn_val == 0)
        val->turn++;
    return (i);
}

char *append(char *result, char *buff, int i, val_t *val)
{
    int j = 0;

    val->carac += i;
    result = malloc(sizeof(char) * val->carac + 1);
    for (; j != val->carac-i; j++)
        result[j] = val->buff_inter[j];
    for (int k = 0; j != val->carac; j++, k++)
        result[j] = buff[k];
    val->buff_inter = malloc(sizeof(char) * val->carac);
    for (int z = 0; z != val->carac; z++)
        val->buff_inter[z] = result[z];
    result[val->carac] = '\0';
    return (result);
}

int set_end(val_t *val)
{
    free(val);
    return (1);
}

char *get_next_line(int fd)
{
    static char *buff;
    char *result;
    static int count_run = 0;
    int i = 0;
    val_t *val = NULL;

    val = malloc(sizeof(val_t));
    val->turn = 1;
    val->carac = 0;
    while (val->turn != 0) {
        val->turn = 0;
        buff = read_next_n_bytes(fd, READ_SIZE, count_run, buff);
        for (; count_run == 1; count_run = 0);
        if (buff) {
            i = read_and_display_read_line_n(buff, val);
            result = append(result, buff, i, val);
        }
    }
    count_run = set_end(val);
    return (result);
}