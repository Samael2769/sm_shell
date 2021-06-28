/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** add_line
*/

#include "my.h"
#include <stdlib.h>

char **add_line(char **tab, char *line)
{
    char **dup = malloc(sizeof(char *) * (count_tab(tab) + 2));
    int i = 0;

    for (; tab[i] != NULL; ++i) {
        dup[i] = my_strdup(tab[i]);
    }
    dup[i] = my_strdup(line);
    dup[i + 1] = NULL;
    return dup;
}