/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** manage_pipe.c
*/

#include "include/my.h"
#include "include/minishell.h"

int exec_without_fork(char *cmd, char **args, char **env, char **path)
{
    char *link_folder = NULL;
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

void close_fd(int *fd)
{
    close(fd[0]);
    close(fd[1]);
}

int exec_pipe1(int *fd, char **av, char **env, char **path)
{
    int pid1 = fork();
    if (pid1 < 0)
        exit(84);
    if (pid1 == 0) {
        dup2(fd[1], STDOUT_FILENO);
        close_fd(fd);
        exec_without_fork(av[0], av, env, path);
    }
    return pid1;
}

int exec_with_pipe(char *cmd, UNUSED int ac, char **env, char **path)
{
    char **av = NULL;
    int fd[2];
    int ret1;
    int ret2;
    char **list_cmd = parse_command(cmd, "|");
    av = parse_command(list_cmd[0], " \t\n");
    char **av2 = parse_command(list_cmd[1], " \t\n");
    if (pipe(fd) == -1)
        exit(84);
    int pid1 = exec_pipe1(fd, av, env, path);
    int pid2 = fork();
    if (pid2 == 0) {
        dup2(fd[0], STDIN_FILENO);
        close_fd(fd);
        exec_without_fork(av2[0], av2, env, path);
    }
    close_fd(fd);
    ret1 = waitpid(pid1, NULL, 0);
    ret2 = waitpid(pid2, NULL, 0);
    return (ret1 != 0 || ret2 != 0) ? -1 : 0;
}
