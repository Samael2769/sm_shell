/*
** EPITECH PROJECT, 2020
** Task03_Pool_Day04
** File description:
** display a number of caracter
*/

int my_strlen(char const *str)
{
    int i = 0;
    int count = 0;
    while (str[i] != '\0') {
        count++;
        i++;
    }

    return (count);
}

