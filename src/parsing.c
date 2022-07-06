/*
** GLOBAL GAME JAM, 2018
** Home Sweet Home
** File description:
** Parsing file
*/

#include "ggj.h"
#include <stdio.h>
#include <stdlib.h>

int *get_info_elem(char *line)
{
    int i = 0;
    int *info = NULL;
    int i_info = 0;

    info = malloc(sizeof(int) * 4);
    if (info == NULL)
        return (NULL);
    while (line[i] != 0 && line[i] != '\n') {
        info[i_info] = getnbr(line + i);
        if (info[i_info++] < 0)
            return (NULL);
        while (line[i] >= '0' && line[i] <= '9')
            i++;
        if (line[i] == ' ')
            i++;
    }
    if (i == 0)
        return (NULL);
    info[i_info] = 0;
    return (info);
}

platform *new_elem(platform *head, char *line)
{
    int *info = get_info_elem(line);
    platform *new_platform = NULL;

    if (info == NULL)
        return NULL;
    new_platform = malloc(sizeof(platform));
    new_platform->x = info[0];
    new_platform->x_end = info[1];
    new_platform->y = info[2];
    new_platform->vector.x = info[0];
    new_platform->vector.y = info[2];
    new_platform->next = head;
    free(info);
    return (new_platform);
}

platform *create_platform(char *path)
{
    FILE *fp = fopen(path, "r");
    platform *head = NULL;
    char *line = NULL;
    size_t len = 0;

    if (fp == NULL)
        return (NULL);
    while (getline(&line, &len, fp) > 0)
        head = new_elem(head, line);
    return (head);
}
