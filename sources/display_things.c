/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** display_things
*/

#include "mysh.h"

void display_error(shell_t *shell)
{
    if (shell->error_nb == 1) {
        my_put_error(shell->cmd_t.argv_cmd[0]);
        my_put_error(": Permission denied.\n");
        shell->exit_status = 1;
    }
    if (shell->error_nb == 2) {
        my_put_error(shell->cmd_t.argv_cmd[0]);
        my_put_error(": Command not found.\n");
        shell->exit_status = 1;
    }
}

int display_env(shell_t *shell)
{
    for (int i = 0; shell->env[i] != NULL; i++)
        my_printf("%s\n", shell->env[i]);
    return 0;
}