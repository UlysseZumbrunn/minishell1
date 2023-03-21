/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell1-ulysse.zumbrunn
** File description:
** step4
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/limits.h>
#include <limits.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "struct.h"
#include "shell.h"
#include "my.h"
#include "constant.h"

int builtin_path(char *command)
{
    return (my_strcmp(command, "cd") == 0 ||
            my_strcmp(command, "exit") == 0);
}

char *goto_path(char *program)
{
    char *path = getenv("PATH");
    char *token;
    struct stat sb;
    char *program_path = malloc(MAX_PATH_LENGTH);

    if (!program_path)
        return NULL;

    token = strtok(path, ":");
    while (token) {
        my_strcpy(program_path, token);
        my_strcat(program_path, "/");
        my_strcat(program_path, program);
        if (stat(program_path, &sb) == 0 && sb.st_mode & S_IXUSR)
            return program_path;
        token = strtok(NULL, ":");
    }

    free(program_path);
    return NULL;
}
