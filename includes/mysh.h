/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my
*/

#ifndef MYSH_H
#define MYSH_H

#define RED "\e[1;31m"
#define BLACK "\e[1;30m"
#define NO_COL "\e[0m"
#include "my.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <signal.h>

typedef struct cd_s {
    char *save_pwd;
    char *pwd;
} cd_t;

typedef struct prompt_s {
    char *username;
    char *pwd;
    int status;
} prompt_t;

typedef struct cmd_s {
    char *cmd;
    char **argv_cmd;
} cmd_t;

typedef struct redi_s {
    char *input;
    char *output;
    char *str_input;
    int fd_input;
    int fd_output;
    int type_right;
    int type_left;
} redi_t;

typedef struct shell_s {
    char **env;
    char **path_tab;
    char *cmd;
    char *exec;
    int exit_status;
    int error_nb;
    cmd_t cmd_t;
    cd_t cd;
    prompt_t prompt;
    bool is_env;
    redi_t redi;
} shell_t;

int init_env(shell_t *shell, char **env);
int mysh(shell_t *shell);
void free_shell(shell_t *shell);
void free_argv(shell_t *shell, char *str);
int show_prompt(shell_t *shell);
int chose_type(shell_t *shell);
int check_syscmd(shell_t *shell);
int check_mycmd(shell_t *shell);
int command_exec(shell_t *shell);
void display_error(shell_t *shell);
int display_env(shell_t *shell);
int my_cd(shell_t *shell);
int my_setenv(shell_t *shell);
int my_unsetenv(shell_t *shell);
int stock_env(shell_t *shell, char **env);
int init_cmd(shell_t *shell);
int complex_cmd(shell_t *shell);
int init_redirect(shell_t *shell);
int chose_fct(shell_t *shell);
int make_redirect(shell_t *shell);
void parent_process(int *exit_status, int status);
int make_pipe(shell_t *shell);
int redirect_all(shell_t *shell);

#endif /* !MYSH_H */