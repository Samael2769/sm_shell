/*
** EPITECH PROJECT, 2020
** Include
** File description:
** lib
*/

#ifndef MY_H
#define MY_H

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);
char *my_strdup(char const *src);
char **str_to_word_array(char *str, char pars);
int my_printf(char *s, ...);
int my_strncmp(char const *s1, char const *s2, int n);
char **tab_dup(char **tab, int len);
int count_tab(char **tab);
char **supp_line(char **tab, int index);
char *clean_string(char *str);
int my_put_error(char *str);
char *read_buff(char *filepath);
int find_line(char **tab, char *line);
int my_puttab(char **tab);
void free_tab(char **tab, int len);
char **add_line(char **tab, char *line);
char *get_buffer(char *filepath);
int count_char(char *str, char a);

typedef struct stat stat_t;

#endif /* My_H */