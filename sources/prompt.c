/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** prompt
*/

#include "mysh.h"

static int get_name(prompt_t *prompt, char **env)
{
    int index = find_line(env, "USER=");

    if (index != (-1))
        prompt->username = my_strdup(env[index] + 5);
    return 0;
}

static int get_dir(prompt_t *prompt, char **env)
{
    int index = find_line(env, "PWD=");
    char **dup;

    if (index != (-1)) {
        dup = str_to_word_array(env[index] + 4, '/');
        prompt->pwd = my_strdup(dup[count_tab(dup) - 1]);
        free_tab(dup, count_tab(dup));
    }
    return 0;
}

static int set_prompt(shell_t *shell)
{
    get_name(&shell->prompt, shell->env);
    get_dir(&shell->prompt, shell->env);
    return 0;
}

static void display_prompt(shell_t *shell)
{
    if (shell->is_env == true) {
        set_prompt(shell);
        my_printf("[%s%s%s:%s%s%s]\n⤬➜ ",
        BLACK, shell->prompt.username, NO_COL, RED,
        shell->prompt.pwd, NO_COL);
    }else
        my_printf("$> ");
}

int show_prompt(shell_t *shell)
{
    if (isatty(0) == 1)
        display_prompt(shell);
    return 0;
}