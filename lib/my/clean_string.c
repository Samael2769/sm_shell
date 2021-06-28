/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** string
*/

#include <unistd.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *loop_clean(char *str, char *str2, int *j2)
{
    int j = *j2;

    for (int i = 0; str[i] != '\0'; i++) {
        for (;str[i] == ' ' || str[i] == '\t' ||
        str[i] == '\n' || str[i] == '"'; i++)
            ;
        for (;(str[i] != ' ' && str[i] != '\t' && str[i]
        != '\n' && str[i] != '"') && str[i] != '\0'; i++, j++) {
            str2[j] = str[i];
        }
        if (str[i] == '\0')
            break;
        str2[j] = ' ';
        j++;
    }
    *j2 = j;
    return str2;
}

char *clean_string(char *str)
{
    int j = 0;
    int len = my_strlen(str);
    char *str2 = malloc(sizeof(char) * (len + 1));

    str2 = loop_clean(str, str2, &j);
    if (str2[j - 1] == ' ')
        str2[j - 1] = '\0';
    else
        str2[j] = '\0';
    return str2;
}