/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell1-ulysse.zumbrunn
** File description:
** read_input
*/

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


int make_my_builtin(char **args, char **envp)
{
    int status;
    pid_t pid = fork();
    if (pid == 0) {
        if (execve(args[0], args, envp) == -1) {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else {
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        }
    }
    return 1;
}

int recur_read_my_input(char **args, char **env)
{
    char *path = goto_path(args[0]);
    if (!path) {
        const char* error_msg = args[0];
        const char* error_suffix = ": command not found\n";
        write(STDERR_FILENO, error_msg, my_strlen(error_msg));
        write(STDERR_FILENO, error_suffix, my_strlen(error_suffix));
        return 1;
    }

    free(args[0]);
    args[0] = path;
    int status = make_my_builtin(args, env);
    return status;
}

int read_my_input(char *command, char **env)
{
    char **args = fill_my_args(command);
    int status = 0;

    if (!args || !args[0])
        return 1;

    if (builtin_path(args))
        status = my_builtin_cmd(args);
    else if (recur_read_my_input(args, env) == -1) {
        const char* error_msg = args[0];
        const char* error_suffix = ": command not found\n";
        write(STDERR_FILENO, error_msg, my_strlen(error_msg));
        write(STDERR_FILENO, error_suffix, my_strlen(error_suffix));
        status = 1;
    }
    my_args(args);
    return status;
}

void my_args(char **args)
{
    int i = 0;
    while (args[i] != NULL) {
        free(args[i]);
        i++;
    }
    free(args);
}

char **fill_my_args(char *line)
{
    char **args = malloc(MAX_ARGS * sizeof(char *));
    char *arg = strtok(line, " \t\n");

    int i = 0;
    while (arg != NULL) {
        args[i] = my_strdup(arg);
        arg = strtok(NULL, " \t\n");
        i++;
    }
    args[i] = NULL;
    return args;
}
