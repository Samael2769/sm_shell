/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** pipe
*/

#include "mysh.h"

static int child_process(shell_t *shell, char **pipes)
{

    for (int i = 0; pipes[i] != NULL; ++i) {
        shell->cmd_t.cmd = my_strdup(pipes[i]);
        if (redirect_all(shell) == -1)
            return (-1);
    }
    return 0;
}

int make_pipe(shell_t *shell)
{
    char **pipes = str_to_word_array(shell->cmd_t.cmd, '|');
    int status = 0;
    int pid = fork();

    if (pid == -1) {
        my_put_error("Error fork\n");
    } else if (pid == 0) {
        if (child_process(shell, pipes) == -1)
            exit(-1);
        exit(0);
    } else {
        parent_process(&shell->exit_status, status);
    }
    if (shell->exit_status == 255)
        return (-1);
    return 0;
}