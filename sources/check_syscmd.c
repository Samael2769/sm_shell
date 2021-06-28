/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** check_syscmd
*/

#include "mysh.h"

int check_access(char **cmd, char *path)
{
    if (access(path, F_OK) == 0) {
        if (access(path, X_OK) == 0) {
            cmd[0] = my_strdup(path);
            return 0;
        }
        return 1;
    }
    return 2;
}

int check_syscmd(shell_t *shell)
{
    char *cmd = my_strcat("/", shell->cmd_t.argv_cmd[0]);
    char *path = NULL;

    stock_env(shell, shell->env);
    for (int i = 0; shell->path_tab[i] != NULL; ++i) {
        path = my_strcat(shell->path_tab[i], cmd);
        shell->error_nb = check_access(&shell->exec, path);
        if (shell->error_nb == 0) {
            free(path);
            free(cmd);
            return 0;
        }
        free(path);
    }
    return (-1);
}

int check_mycmd(shell_t *shell)
{
    shell->error_nb = check_access(&shell->exec, shell->cmd_t.argv_cmd[0]);
    return shell->error_nb;
}