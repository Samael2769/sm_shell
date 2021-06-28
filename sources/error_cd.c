/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** error_cd
*/

#include "mysh.h"
#include <errno.h>

void errno_cd(int nb, shell_t *shell)
{
    if (nb == EACCES) {
        my_put_error(shell->cmd_t.argv_cmd[1]);
        my_put_error(": Permission denied.\n");
    }
    if (nb == ENOTDIR) {
        my_put_error(shell->cmd_t.argv_cmd[1]);
        my_put_error(": Not a directory.\n");
    }
    if (nb == ENOENT) {
        my_put_error(shell->cmd_t.argv_cmd[1]);
        my_put_error(": No such file or directory.\n");
    }
}