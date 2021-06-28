/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** mysh
*/

#include "mysh.h"
#include <stdio.h>

int chose_fct(shell_t *shell)
{
    int type = 0;
    if (my_strcmp(shell->cmd_t.argv_cmd[0], "exit") == 0)
        return (-1);
    type = chose_type(shell);
    if (type == 1)
        command_exec(shell);
    if (type == 0)
        return 0;
    if (type == (-1))
        display_error(shell);
    return 0;
}

int init_cmd(shell_t *shell)
{
    char *str = clean_string(shell->cmd_t.cmd);

    shell->cmd_t.argv_cmd = str_to_word_array(str, ' ');
    if (chose_fct(shell) == (-1)) {
        free_argv(shell, str);
        return (-1);
    }
    free_argv(shell, str);
    return 0;
}

int mysh(shell_t *shell)
{
    int eof = 0;
    size_t nb = 0;

    shell->exit_status = 0;
    while (eof != (-1)) {
        shell->cmd = NULL;
        show_prompt(shell);
        signal(SIGINT, SIG_IGN);
        if (getline(&shell->cmd, &nb, stdin) == (-1))
            break;
        if (my_strncmp(shell->cmd, "\n", 1) == 0) {
            free(shell->cmd);
            continue;
        }
        eof = complex_cmd(shell);
        free(shell->cmd);
    }
    return shell->exit_status;
}