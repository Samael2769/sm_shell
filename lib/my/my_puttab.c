/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_puttab
*/
#include "my.h"
#include <unistd.h>

int my_puttab(char **tab)
{
    if (tab == NULL)
        return (-1);
    for (int i = 0; tab[i] != NULL; ++i) {
        write(1, tab[i], my_strlen(tab[i]));
        write(1, "\n", 1);
    }
    return 0;
}