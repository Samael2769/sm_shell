/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** unsetenv
*/

#include "mysh.h"

int my_unsetenv(shell_t *shell)
{
    char **tab = NULL;
    int nb = (-1);
    char *line;

    if (count_tab(shell->cmd_t.argv_cmd) < 2) {
        my_put_error("unsetenv: Too few arguments.\n");
        shell->exit_status = 1;
        return 0;
    }
    for (int j = 1; shell->cmd_t.argv_cmd[j] != NULL; ++j) {
        line = my_strcat(shell->cmd_t.argv_cmd[j], "=");
        nb = find_line(shell->env, line);
        if (nb == (-1))
            continue;
        tab = supp_line(shell->env, nb);
        shell->env = tab_dup(tab, count_tab(tab));
        free_tab(tab, count_tab(tab));
    }
    return 0;
}