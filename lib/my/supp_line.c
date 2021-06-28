/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** supp_line
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src);

int count_tab(char **tab);

char **supp_line(char **tab, int index)
{
    int i = 0;
    int j = 0;
    char **dest = malloc(sizeof(char *) * count_tab(tab));

    for (; tab[i] != NULL; ++i, ++j) {
        if (j == index)
            ++j;
        dest[i] = tab[j];
    }
    return dest;
}