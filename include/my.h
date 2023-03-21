/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell1-ulysse.zumbrunn
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #define MAX_PATH_LENGTH 256
    #define MAX_DIR_LENGTH 256
    #define MAX_ERROR_LENGTH 1024
    #define MAX_CMD_LENGTH 1024
    #define MAX_ARGS 64

int main(void);
int cmd_exec(char **args, char **envp);
int run_my_cmd(char *command, char **env);
int builtin_path(char *command);

char *goto_path(char *program);
void my_args(char **args);
char **fill_my_args(char *line);
int my_builtin_cmd(char **args);

int make_my_builtin(char **args, char **envp);
void exit_cmd(int status, char *buf, int *n);
int my_cmd_execute(char **argv);
void my_print_info(void);

char* fill_info(void);
int fill_cmd(char *command);
int my_cmd_exec2(char **args);
char *my_strcat(char *first, char *second);

char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *z1,char const *z2);
int read_my_input(char *command, char **env);
int recur_read_my_input(char **args, char **env);

int my_putstr(char const *str);
void recurexecute(char **args);

int my_strcmp(char const *z1,char const *z2);
char *my_strdup(char const *src);
int my_putstr(char const *str);
void my_putchar(char c);
int my_strlen(char const *str);
char* my_getenv(const char* path);

void clear_fct(DIR *dirp, char **args, int argc);
static void recurclear(char **args, int i);
int my_strncmp(char const *s1, char const *s2, int n);
int check_for_ampersand(char **args);

#endif /* !MY_H_ */
