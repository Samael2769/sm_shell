/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** count_tab
*/

#include <stddef.h>
#include <stdlib.h>

int count_tab(char **tab)
{
    int count = 0;
    for (; tab[count] != NULL; count++);
    return count;
}