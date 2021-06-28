/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** find_line
*/

#include "my.h"
#include  <stddef.h>

int find_line(char **tab, char *line)
{
    int i;

    if (line == NULL)
        return (-1);
    for (i = 0; tab[i] != NULL; ++i)
        if (my_strncmp(tab[i], line, my_strlen(line)) == 0)
            return i;
    if (i == count_tab(tab))
        return (-1);
}