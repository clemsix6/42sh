/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** exec.c
*/

#include "include/my.h"
#include "include/minishell.h"

void exec_condition(char *link_folder, char **args, char **env)
{
    if (execve(link_folder, args, env) == -1)
        exit(84);
}

char *build_link_folder(char **path, int i, char *cmd)
{
    char *link_folder = NULL;
    link_folder = add_char(path[i], '/');
    link_folder = add_str(link_folder, cmd);
    return link_folder;
}

int exec(char *cmd, char **args, char **env, char **path)
{
    char *link_folder = NULL;
    pid_t pid = getpid();
    int status = 0;

    if (fork() == -1)
        return 84;
    if (getpid() == pid) {
        waitpid(NULL, &status, 0);
        return status != 0 ? 84 : 0;
    }
    for (int i = 0; path[i] != NULL; i++){
        link_folder = build_link_folder(path, i, cmd);
        if (access(link_folder, F_OK) == 0) {
            exec_condition(link_folder, args, env);
        }
    }
    my_putstr(cmd);
    my_putstr(": Command not found.\n");
    free(link_folder);
    exit(0);
}

int link_exec(char *cmd, char **args, char **env)
{
    pid_t pid = getpid();
    int *status = 0;

    if (fork() == -1)
        return 84;
    if (getpid() == pid) {
        waitpid(pid, status, 0);
        return status != 0 ? 84 : 0;
    }
    execve(cmd, args, env);
    exit(0);
}

int execution(char **av, char **env, char **path)
{
    if (av[0][0] == '/' || av[0][0] == '.') {
        return link_exec(av[0], av, env);
    } else {
        return exec(av[0], av, env, path);
    }
}
