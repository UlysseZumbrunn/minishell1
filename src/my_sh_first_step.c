/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell1-ulysse.zumbrunn
** File description:
** my_sh_first_step print_info
*/


/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell1-ulysse.zumbrunn
** File description:
** my_sh_first_step print_info
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

void my_print_info(void)
{
    char cwd[MAX_DIR_LENGTH];
    char prompt[MAX_DIR_LENGTH + 3];

    if (getcwd(cwd, MAX_DIR_LENGTH) == NULL) {
        perror("getcwd() error");
        exit(EXIT_FAILURE);
    }
    my_strcpy(prompt, "$> ");
    write(STDOUT_FILENO, prompt, my_strlen(prompt));
}

char *fill_info(void)
{
    char *input = NULL;
    size_t size = 0;

    if (getline(&input, &size, stdin) == -1) {
        exit(EXIT_FAILURE);
    }
    return input;
}

int fill_cmd(char *command)
{
    char **args = fill_my_args(command);
    int status = 0;

    if (args == NULL || args[0] == NULL) {
        return 1;
    }

    if (builtin_path(args)) {
        status = my_builtin_cmd(args);
    } else {
        status = my_cmd_exec2(args);
    }

    my_args(args);
    return status;
}

int my_cmd_exec2(char **args)
{
    char *path = goto_path(args[0]);
    if (path == NULL) {
        char error_msg[MAX_ERROR_LENGTH];
        my_strcpy(error_msg, "Command not found: ");
        my_strcat(error_msg, args[0]);
        write(STDERR_FILENO, error_msg, my_strlen(error_msg));
        write(STDERR_FILENO, "\n", 1);
        return 1;
    }

    free(args[0]);
    args[0] = path;
    int status = my_cmd_execute(args);
    return status;
}

int main(void)
{
    while (1) {
        my_print_info();
        char *input = fill_info();
        int status = fill_cmd(input);
        free(input);
    }

    return 0;
}
