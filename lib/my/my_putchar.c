/*
** EPITECH PROJECT, 2020
** My_putchar
** File description:
** Put a char
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

