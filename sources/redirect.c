/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** redirect
*/

#include "mysh.h"

static int check_redi(int *type, char *redi, char *str)
{
    if (my_strcmp(str, redi) == 0) {
        if(type[0] != 0) {
            my_put_error("Ambiguous ");
            if (my_strncmp(redi, "<", 1) == 0)
                my_put_error("input");
            else
                my_put_error("output");
            my_put_error(" redirect.\n");
            return (-1);
        }
        type[0] = my_strlen(redi);
    }
    return 0;
}

static int chose_side(shell_t *shell, char *str)
{
    if (check_redi(&shell->redi.type_left, "<", str) != 0)
        return (-1);
    if (check_redi(&shell->redi.type_right, ">", str) != 0)
        return (-1);
    if (check_redi(&shell->redi.type_left, "<<", str) != 0)
        return (-1);
    if (check_redi(&shell->redi.type_right, ">>", str) != 0)
        return (-1);
    return 0;
}

static int find_redirect_bis(shell_t *shell, char ***tab, int *i)
{
    if (shell->redi.type_right != 0 && my_strncmp(tab[0][*i], ">", 1) == 0) {
        if (tab[0][*i + 1] != NULL) {
            shell->redi.output = my_strdup(tab[0][*i + 1]);
            tab[0] = supp_line(tab[0], *i + 1);
        } else {
            my_put_error("Missing name for redirect.\n");
            return (-1);
        }
        tab[0] = supp_line(tab[0], *i);
        *i = 0;
    }
    return 0;
}

static int find_redirect(shell_t *shell, char ***tab)
{
    for (int i = 0; tab[0][i] != NULL; ++i) {
        if (chose_side(shell, tab[0][i]) != 0)
            return (-1);
        if (shell->redi.type_left != 0 && my_strncmp(tab[0][i], "<", 1) == 0) {
            if (tab[0][i + 1] != NULL) {
                shell->redi.input = my_strdup(tab[0][i + 1]);
                tab[0] = supp_line(tab[0], i + 1);
            } else {
                my_put_error("Missing name for redirect.\n");
                return (-1);
            }
            tab[0] = supp_line(tab[0], i);
            i = 0;
        }
        if (find_redirect_bis(shell, tab, &i) == (-1))
            return (-1);
    }
    return 0;
}

int init_redirect(shell_t *shell)
{
    char *str = clean_string(shell->cmd_t.cmd);
    char **tab = str_to_word_array(str, ' ');

    shell->redi.type_left = 0;
    shell->redi.type_right = 0;
    if (find_redirect(shell, &tab) != 0) {
        free(str);
        free_tab(tab, count_tab(tab));
        shell->exit_status = 1;
        return (0);
    }
    shell->cmd_t.argv_cmd = tab_dup(tab, count_tab(tab));
    if (make_redirect(shell) == (-1))
        return (-1);
    free(str);
    free_tab(tab, count_tab(tab));
    return 0;
}