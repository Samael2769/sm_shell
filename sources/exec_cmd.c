/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** exec_cmd
*/

#include "mysh.h"
#include <sys/wait.h>

void parent_process(int *exit_status, int status)
{
    wait(&status);
    if (WIFSIGNALED(status))
    {
        *exit_status = WTERMSIG(status);
        if (WTERMSIG(status) == SIGSEGV)
            my_put_error("Segmentation fault\n");
        return;
    }
    if (WIFEXITED(status)) {
        *exit_status = WEXITSTATUS(status);
        return;
    }
    if (WIFSTOPPED(status))
        *exit_status = WSTOPSIG(status);
}

int command_exec(shell_t *shell)
{
    pid_t pid = fork();
    int status = 0;

    if (pid == -1) {
        my_printf("error");
    } else if (pid == 0) {
        signal(SIGINT, SIG_DFL);
        if (execve(shell->exec, shell->cmd_t.argv_cmd, shell->env) == -1) {
            my_put_error(shell->cmd_t.argv_cmd[0]);
            my_put_error(": Permission denied.\n");
            exit(1);
        }
    } else {
        parent_process(&shell->exit_status, status);
    }
    free(shell->exec);
    return 0;
}