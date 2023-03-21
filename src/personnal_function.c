/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell1-ulysse.zumbrunn
** File description:
** personnal_function
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

int my_strcmp(char const *z1,char const *z2)
{
    int j = 0;

    while (z2[j] != '\0' && z1[j] != '\0' && z2[j] == z1[j])
        j++;
            if (z2[j] < z1[j])
        return 1;
    else if (z2[j] > z1[j])
        return -1;
    else
        return 0;
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int u = 0; str[u] != '\0'; u++)
        my_putchar(str[u]);
}

char *my_strdup(char const *src)
{
    char *dest = NULL;
    int i = 0;

    if (src == NULL)
        return (NULL);
    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (dest == NULL) {
        my_putstr("Error : malloc fail");
        return (NULL);
    }
    for (; dest && src[i]; i++) {
        dest[i] = src[i];
        dest[i + 1] = '\0';
    }
    return (dest);
}
