/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init_buffer
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char *get_buffer(char *filepath)
{
    char *buffer;
    struct stat ap;
    int fd = 0;
    size_t size = 0;

    if (stat(filepath, &ap) == -1)
        return (NULL);
    size = ap.st_size;
    fd = open(filepath, O_RDONLY);
    if (fd < 0 || size <= 0)
        return (NULL);
    buffer = malloc(sizeof(char) * size + 1);
    if (buffer == NULL)
        return (NULL);
    if (read(fd, buffer, size) != size)
        return (NULL);

    buffer[size] = '\0';
    close(fd);
    return (buffer);
}