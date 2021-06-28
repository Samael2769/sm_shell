/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** count_char
*/

int count_char(char *str, char a)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == a)
            nb++;
    }
    return nb;
}