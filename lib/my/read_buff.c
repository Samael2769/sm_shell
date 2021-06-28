/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** read_buff
*/
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "my.h"

char *read_buff(char *filepath)
{
    stat_t stats;
    char *buffer;
    int fd = open(filepath, O_RDONLY);

    if (fd == (-1))
        return NULL;
    if (stat(filepath, &stats) == (-1))
        return NULL;
    buffer = malloc(sizeof(char) * (stats.st_size + 1));
    if (read(fd, buffer, stats.st_size) == (-1))
        return NULL;
    return buffer;
}