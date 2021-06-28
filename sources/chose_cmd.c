/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** chose_cmd
*/

#include "builtin.h"

static int check_builtin(shell_t *shell)
{
    for (int i = 0; i < tab_size; ++i) {
        if (my_strcmp(b_tab[i].builtin, shell->cmd_t.argv_cmd[0]) == 0) {
            b_tab[i].ptr(shell);
            return 0;
        }
    }
    return (-1);
}

int chose_type(shell_t *shell)
{
    int builtin = check_builtin(shell);
    int sys_cmd = check_syscmd(shell);
    int my_cmd = check_mycmd(shell);

    if (builtin == 0)
        return 0;
    if (sys_cmd == 0)
        return 1;
    if (my_cmd == 0)
        return 1;
    return (-1);
}

