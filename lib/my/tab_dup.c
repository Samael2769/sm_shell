/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** tab_dup
*/

#include <stddef.h>
#include <stdlib.h>

char *my_strdup(char const *src);

char **tab_dup(char **tab, int len)
{
    char **dup;
    dup = malloc(sizeof(char *) * (len + 1));
    for (int i = 0; tab[i] != NULL; i++) {
        dup[i] = my_strdup(tab[i]);
    }
    dup[len] = NULL;
    return dup;
}