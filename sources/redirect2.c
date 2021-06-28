/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** redirect2
*/

#include "mysh.h"
#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>

static int input_double(shell_t *shell)
{
    char *str = NULL;
    size_t nb = 0;

    for (int i = 0; 1; ++i) {
        my_printf("? ");
        if (getline(&str, &nb, stdin) == (-1))
            return (-1);
        if (my_strcmp(str, my_strcat(shell->redi.input, "\n")) == 0)
            break;
        if (i != 0)
            shell->redi.str_input = my_strcat(shell->redi.str_input, str);
        else
            shell->redi.str_input = my_strdup(str);
    }
    shell->redi.fd_input = open(".dup", O_CREAT | O_RDWR | O_TRUNC, 0664);
    write(shell->redi.fd_input, shell->redi.str_input,
    my_strlen(shell->redi.str_input));
    shell->redi.fd_input = open(".dup", O_RDONLY);
    return 0;
}

static int get_input(shell_t *shell)
{
    if (shell->redi.type_left == 1) {
        shell->redi.fd_input = open(shell->redi.input, O_RDONLY);
        if (shell->redi.fd_input == (-1)) {
            my_put_error(shell->redi.input);
            my_put_error(": No such file or directory.\n");
            return (-1);
        }
    }
    if (shell->redi.type_left == 2) {
        if (input_double(shell) == (-1))
            return (-1);
    }
    return 0;
}

static int get_output(shell_t *shell)
{
    shell->redi.fd_output = 1;
    if (shell->redi.type_right == 1) {
        shell->redi.fd_output =
        open(shell->redi.output, O_RDWR | O_CREAT | O_TRUNC, 0664);
    }
    if (shell->redi.type_right == 2) {
        shell->redi.fd_output =
        open(shell->redi.output, O_RDWR | O_CREAT | O_APPEND, 0664);
    }
    return 0;
}

int make_redirect(shell_t *shell)
{
    pid_t pid;
    int status = 0;

    if (get_input(shell) != 0)
        return 0;
    get_output(shell);
    pid = fork();
    if (pid == (-1)) {
        my_printf("error fork\n");
    } else if (pid == 0) {
        signal(SIGINT, SIG_DFL);
        dup2(shell->redi.fd_input, 0);
        dup2(shell->redi.fd_output, 1);
        if (chose_fct(shell) == (-1))
            exit(-1);
        exit(shell->exit_status);
    } else
        parent_process(&shell->exit_status, status);
    if (shell->exit_status == 255)
        return (-1);
    return 0;
}