/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** free_tab
*/

#include <stdlib.h>

void free_tab(char **tab, int len)
{
    for (int i = 0; i < len; ++i) {
        free(tab[i]);
    }
    free(tab);
}