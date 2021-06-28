/*
** EPITECH PROJECT, 2020
** Task06_Day05
** File description:
** Reproduce the behavior of my_strcmp
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int res = 0;

    if (my_strlen(s1) != my_strlen(s2))
        return (-1);
    while (s1[i] != '\0' && s2[i] != '\0') {
        res = s1[i] - s2[i];
        if (res != 0)
            return res;
        i++;
    }
    return res;
}
