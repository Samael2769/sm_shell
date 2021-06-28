/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/
#include "mysh.h"

static const char *usage = {
    "USAGE:\n"
    "\t./mysh [-h]\n"
    "    $> commands [argvs]\n"
};

int main(int ac, char **av, char **env)
{
    shell_t shell;
    int nb = 0;

    if (ac > 2)
        return (84);
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (my_putstr(usage));
    (shell.is_env = (env[0] != NULL));
    init_env(&shell, env);
    nb = mysh(&shell);
    free_tab(shell.env, count_tab(shell.env));
    return nb;
}