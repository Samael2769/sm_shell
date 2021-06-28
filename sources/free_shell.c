/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** free_shell
*/

#include "mysh.h"

void free_argv(shell_t *shell, char *str)
{
    free(str);
    free_tab(shell->cmd_t.argv_cmd, count_tab(shell->cmd_t.argv_cmd));
}