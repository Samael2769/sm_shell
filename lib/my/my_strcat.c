/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** my_strcat
*/

#include <stdlib.h>
#include <unistd.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    char *new_str = malloc(sizeof(char) * (my_strlen(dest)
    + my_strlen(src) + 1));

    for (; dest[i] != '\0'; i++) {
        new_str[i] = dest[i];
    }
    for (int j = 0; src[j] != '\0'; j++, i++) {
        new_str[i] = src[j];
    }
    new_str[i] = '\0';
    return new_str;
}