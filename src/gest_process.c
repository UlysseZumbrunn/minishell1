/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell1-ulysse.zumbrunn
** File description:
** gest_process step 3
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
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

void exit_cmd(int status, char *buf, int *n)
{
    if (status >= 10) {
        exit_cmd(status / 10, buf, n);
    }
    buf[(*n)++] = (status % 10) + '0';
}

int my_cmd_execute(char **argv)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execute_cmd");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        perror("execute_cmd");
    } else {
        waitpid(pid, &status, 0);
    }
}
