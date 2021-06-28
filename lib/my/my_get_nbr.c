/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** get a number from a string
*/

int nbrloop(char **src, int x)
{
    int i = x;
    int count = 0;
    char *str = *src;

    while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
    {
        count = (count + (str[i] - 48)) * 10;
        i++;
    }
    count = count / 10;
    *src = &str[i];
    return count;
}

int operator(char **src, int x)
{
    int i = x;
    int operator = 1;
    char *str = *src;

    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
        {
            operator = - operator;
        }
        else
            operator = operator;
        i++;
    }
    *src = &str[i - 1];
    return operator;
}

int my_getnbr(char *str)
{
    int i = 0;
    int count;
    int total;
    int op = 1;

    for (i = 0; str[i] != '\0'; i++)
    {
        if ((str[0] < '0' || str[0] > '9') &&
        (str[0] != '-' && str[0] != '+') || str[0] == '\0')
            break;
        if (str[i] >= '0' && str[i] <= '9') {
            count = nbrloop(&str, i);
            break;
        }
        if (str[i] == '-') {
            op = operator(&str, i);
        }
    }
    total = count * op;
    return total;
}