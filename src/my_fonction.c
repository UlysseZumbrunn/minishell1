/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell1-ulysse.zumbrunn
** File description:
** my_fonction
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "struct.h"
#include "shell.h"
#include "my.h"
#include "constant.h"

char *my_strcat(char *first, char *second)
{
    char *ptr = first;
    while (*ptr != '\0') {
        ptr++;
    }
    while (*second != '\0') {
        *ptr++ = *second++;
    }
    *ptr = '\0';
    return first;
}

char *my_strcpy(char *dest, const char *src)
{
    size_t i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

int my_builtin_cmd(char **args)
{
    if (my_strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            chdir(my_getenv("HOME"));
        } else {
            if (chdir(args[1]) == -1) {
                perror("cd");
            }
        }
        return 1;
    } else if (my_strcmp(args[0], "exit") == 0) {
        exit(0);
    } else {
        return 0;
    }
}

void recurexecute(char **args)
{
    if (chdir(args[1]) != 0) {
        const char* error_msg = "cd: ";
        const char* error_suffix = ": No such file or directory\n";
        write(STDERR_FILENO, error_msg, my_strlen(error_msg));
        write(STDERR_FILENO, args[1], my_strlen(args[1]));
        write(STDERR_FILENO, error_suffix, my_strlen(error_suffix));
    }
}

char* my_getenv(const char* path)
{
    extern char** environ;
    size_t file = my_strlen(path);
    char** i = environ;
    while (*i != NULL) {
        if (my_strncmp(*i, path, file) == 0 && (*i)[file] == '=') {
            return &((*i)[file + 1]);
        }
        ++i;
    }
    return NULL;
}
