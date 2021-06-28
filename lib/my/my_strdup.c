/*
** EPITECH PROJECT, 2020
** Task01_Day08
** File description:
** allocate memory
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *str;
    int i = 0;
    int count = my_strlen(src);

    str = malloc(sizeof(char) * (count + 1));
    while (src[i] != '\0')
    {
        str[i] = src[i];
        i++;
    }
    str[count] = '\0';
    return str;
}
