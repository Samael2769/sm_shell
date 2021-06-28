/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** setenv
*/

#include "mysh.h"

static int alpha_error(shell_t *shell)
{
    if ((shell->cmd_t.argv_cmd[1][0] < 'A' || shell->cmd_t.argv_cmd[1][0] > 'Z')
    && (shell->cmd_t.argv_cmd[1][0] < 'a'
    || shell->cmd_t.argv_cmd[1][0] > 'z')) {
        my_put_error("setenv: Variable name must begin with a letter.\n");
        shell->exit_status = 1;
        return 1;
    }
    return 0;
}

static int error_setenv(shell_t *shell)
{
    if (count_tab(shell->cmd_t.argv_cmd) > 3) {
        my_put_error(shell->cmd_t.argv_cmd[0]);
        my_put_error(": Too many arguments.\n");
        shell->exit_status = 1;
        return 1;
    }
    for (int i = 0; shell->cmd_t.argv_cmd[1][i] != '\0'; i++)
        if ((shell->cmd_t.argv_cmd[1][i] < 'a' ||
        shell->cmd_t.argv_cmd[1][i] > 'z') &&
        (shell->cmd_t.argv_cmd[1][i] < 'A' ||
        shell->cmd_t.argv_cmd[1][i] > 'Z') &&
        (shell->cmd_t.argv_cmd[1][i] < '0' ||
        shell->cmd_t.argv_cmd[1][i] > '9')) {
            my_put_error(shell->cmd_t.argv_cmd[0]);
            my_put_error(": Variable name must contain");
            my_put_error(" alphanumeric characters.\n");
            shell->exit_status = 1;
            return 1;
        }
    return 0;
}

static int check_setenv(shell_t *shell)
{
    if (shell->cmd_t.argv_cmd[1] == NULL) {
        display_env(shell);
        return 1;
    }
    if (alpha_error(shell) == 1 || error_setenv(shell) == 1)
        return 1;
    return 0;
}

int my_setenv(shell_t *shell)
{
    char *line;
    int nb;
    char **dup;

    if (check_setenv(shell) == 1)
        return 0;
    line = my_strcat(shell->cmd_t.argv_cmd[1], "=");
    nb= find_line(shell->env, line);
    if (shell->cmd_t.argv_cmd[2] == NULL)
        line = my_strcat(line, "");
    else
        line = my_strcat(line, shell->cmd_t.argv_cmd[2]);
    if (nb == (-1)) {
        dup = add_line(shell->env, line);
        shell->env = tab_dup(dup, count_tab(dup));
        free_tab(dup, count_tab(dup));
    } else
        shell->env[nb] = my_strdup(line);
    return 0;
}