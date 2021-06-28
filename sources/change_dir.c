/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** change_dir
*/

#include "mysh.h"
#include <errno.h>

void errno_cd(int nb, shell_t *shell);

int change_pwd(shell_t *shell, char *pwd)
{
    pwd = my_strcat("PWD=", pwd);
    int i = find_line(shell->env, "PWD=");

    if (i != (-1)) {
        shell->cd.save_pwd = my_strdup(shell->env[i]);
        shell->env[i] = my_strdup(pwd);
    }
    return 0;
}

char *get_home(shell_t *shell)
{
    char *home = NULL;
    int i = find_line(shell->env, "HOME=");

    if (i != (-1))
        home = my_strdup(shell->env[i] + 5);
    return home;
}

int check_chdir(shell_t *shell)
{
    char *home;

    if (count_tab(shell->cmd_t.argv_cmd) == 1) {
        home = get_home(shell);
        if (home == NULL)
            return (-1);
        chdir(home);
        return 1;
    }
    if (my_strcmp(shell->cmd_t.argv_cmd[1], "-") == 0) {
        chdir(shell->cd.save_pwd + 4);
        return 1;
    }
    return 0;
}

int error_cd(shell_t *shell)
{
    if (count_tab(shell->cmd_t.argv_cmd) > 2) {
        my_put_error("cd: Too many arguments.\n");
        shell->exit_status = 1;
        return (-1);
    }
    return 0;
}

int my_cd(shell_t *shell)
{
    char *buff = malloc(sizeof(char) * 100);
    int check = check_chdir(shell);

    if (error_cd(shell) == (-1))
        return (-1);
    if (check == 0) {
        if (chdir(shell->cmd_t.argv_cmd[1]) == (-1)) {
            errno_cd(errno, shell);
            shell->exit_status = 1;
        }
    } else if (check == (-1)) {
        my_put_error(shell->cmd_t.argv_cmd[0]);
        my_put_error(": No home directory.\n");
        shell->exit_status = 1;
        return (-1);
    }
    getcwd(buff, 100);
    change_pwd(shell, buff);
    return 0;
}