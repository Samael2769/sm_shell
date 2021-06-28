/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_put_error
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_put_error(char *str)
{
    int len = my_strlen(str);
    write(2, str, len);
    return 0;
}