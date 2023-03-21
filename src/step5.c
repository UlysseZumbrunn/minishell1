/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell1-ulysse.zumbrunn
** File description:
** step5
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <dirent.h>
#include "my.h"
#include "shell.h"
#include "struct.h"
#include "constant.h"

static void recurclear(char **args, int i)
{
    if (args[i] != NULL) {
        free(args[i]);
    }
}

void clear_fct(DIR *dirp, char **args, int argc)
{
    if (dirp != NULL) {
        closedir(dirp);
    }
    if (args != NULL) {
        for (int i = 0; i < argc; i++) {
            recurclear(args, i);
        }
        free(args);
    }
    exit(0);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int count = 0;
    while (count < n && s1[count] != '\0' && s2[count] != '\0') {
        if (s1[count] != s2[count]) {
            return s1[count] - s2[count];
        }
        count++;
    }
    if (count < n) {
        return s1[count] - s2[count];
    }
    return 0;
}
