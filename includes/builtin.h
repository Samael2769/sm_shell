/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** builtin
*/

#ifndef BUILTIN_H_
#define BUILTIN_H_
#include "mysh.h"

typedef struct builtin_s {
    char *builtin;
    int (*ptr)(shell_t *shell);
} builtin_t;

static const builtin_t b_tab[] = {
    {"env", display_env},
    {"setenv", my_setenv},
    {"unsetenv", my_unsetenv},
    {"cd", my_cd},
};

static const int tab_size = sizeof(b_tab) / sizeof(b_tab[0]);

#endif /* !BUILTIN_H_ */