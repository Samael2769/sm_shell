/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** complex_cmd
*/

#include "mysh.h"
#include <string.h>

int redirect_all(shell_t *shell)
{
    int nb_r = count_char(shell->cmd_t.cmd, '>');
    int nb_l = count_char(shell->cmd_t.cmd, '<');

    if (nb_l > 0 || nb_r > 0) {
        if (init_redirect(shell) == (-1))
            return (-1);
        return (1);
    }
    if (init_cmd(shell) == (-1))
        return (-1);
    return 0;
}

static int check_pipe(shell_t *shell)
{
    int redi = 0;

    if (count_char(shell->cmd_t.cmd, '|') != 0) {
        if (make_pipe(shell) == -1)
            return (-1);
        return 1;
    }
    redi = redirect_all(shell);
    if (redi == (-1))
        return (-1);
    if (redi == 1)
        return 1;
    return 0;
}

int complex_cmd(shell_t *shell)
{
    char *str = clean_string(shell->cmd);
    char **cmd = str_to_word_array(str, ';');
    int redi = 0;
    for (int i = 0; cmd[i] != NULL; ++i) {
        shell->cmd_t.cmd = my_strdup(cmd[i]);
        if (my_strcmp(shell->cmd_t.cmd, "") == 0 ||
        my_strcmp(shell->cmd_t.cmd, " ") == 0)
            continue;
        redi = check_pipe(shell);
        if (redi == 1)
            continue;
        if (redi == (-1)) {
            free_tab(cmd, count_tab(cmd));
            return (-1);
        }
        free(shell->cmd_t.cmd);
    }
    free(str);
    free_tab(cmd, count_tab(cmd));
    return 0;
}