/*
** EPITECH PROJECT, 2020
** Task07_Day05
** File description:
** Reproduce the behavior of my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] == s2[i] && i < n - 1) {
        i++;
    }
    return (s1[i] - s2[i]);
}
