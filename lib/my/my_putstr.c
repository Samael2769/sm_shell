/*
** EPITECH PROJECT, 2020
** Task02_Pool_Day04
** File description:
** display a string
*/

#include <unistd.h>

void my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}

