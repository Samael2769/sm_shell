/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** init_env
*/

#include "mysh.h"

int stock_env(shell_t *shell, char **env)
{
    int nb = find_line(env, "PATH=");
    char *path_string;

    if (nb != (-1)) {
        path_string = my_strdup(env[nb]);
        path_string += 5;
        shell->path_tab = str_to_word_array(path_string, ':');
        path_string -= 5;
        free(path_string);
    }
    return 0;
}

int fill_env(shell_t *shell)
{
    char *pwd = malloc(sizeof(char) * 100);
    char *buffer = get_buffer(".env");

    if (buffer == NULL) {
        my_printf("error env\n");
        exit(84);
    }
    shell->env = str_to_word_array(buffer, '\n');
    getcwd(pwd, 100);
    pwd = my_strcat("PWD=", pwd);
    shell->env = add_line(shell->env, pwd);
    return 0;
}

int init_env(shell_t *shell, char **env)
{
    if (shell->is_env == true) {
        stock_env(shell, env);
        shell->env = tab_dup(env, count_tab(env));
    } else
        fill_env(shell);
    return 0;
}