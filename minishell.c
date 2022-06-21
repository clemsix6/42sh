/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** minishell
*/

#include "include/my.h"
#include "include/minishell.h"
#include <stdbool.h>

int basic_execution(char *cmd, int ac, llist ll_env, char **path, char **env)
{
    char **av = parse_command(cmd, " \t\n\0");
    ll_env = get_builtin(ac, av[0], av, ll_env);
    if (ll_env == NULL) {
        return execution(av, env, path);
    }
    free(av);
}

int exec_with_semicolon(char *cmd, int ac, char **env, char **path)
{
    char **list_cmd = NULL;

    list_cmd = parse_command(cmd, ";");
    for (int i = 0; list_cmd[i] != NULL; i++) {
        if (have_pipe(cmd))
            exec_with_pipe(list_cmd[i], ac, env, path);
        else
            basic_execution(list_cmd[i], ac, env_to_ll(env), path, env);
    }
    return 0;
}

int exec_double_esperluette(char *cmd, int ac, char **path, char **env)
{
    char **list_cmd = NULL;

    list_cmd = parse_command(cmd, "&&");
    for (int i = 0; list_cmd[i] != NULL; i++) {
        if (have_pipe(cmd)) {
            if (exec_with_pipe(list_cmd[i], ac, env, path) != 0)
                return -1;
        } else {
            if (basic_execution(list_cmd[i], ac, env_to_ll(env), path, env) != 0)
                return -1;
        }
    }
    return 0;
}

int exec_double_pip(char *cmd, int ac, char **path, char **env)
{
    char **list_cmd = NULL;

    list_cmd = parse_command(cmd, "&&");
    for (int i = 0; list_cmd[i] != NULL; i++) {
        if (have_pipe(cmd)) {
            if (exec_with_pipe(list_cmd[i], ac, env, path) == 0)
                return 0;
        } else {
            if (basic_execution(list_cmd[i], ac, env_to_ll(env), path, env) == 0)
                return 0;
        }
    }
    return -1;
}

int loop(int ac, llist ll_env, char **path, char **env)
{
    char *cmd = NULL;
    size_t len = 0;

    while (42) {
        my_putstr("$> ");
        if (getline(&cmd, &len, stdin) == -1)
            exit(0);
        if (have_double_esperluette(cmd)) {
            exec_double_esperluette(cmd, ac, path, env);
        }else if (have_double_pipe(cmd)) {
            exec_double_pip(cmd, ac, path, env);
        } else if (have_semicolon(cmd)) {
            exec_with_semicolon(cmd, ac, env, path);
        } else if (have_pipe(cmd)) {
            exec_with_pipe(cmd, ac, env, path);
        } else {
            basic_execution(cmd, ac, ll_env, path, env);
        }
    }
    return 0;
}

void minishell(int ac, char **env)
{
    char **path = NULL;
    llist ll_env = env_to_ll(env);
    int index = search_path(env);
    path = parse_path(env[index]);
    loop(ac, ll_env, path, env);
    free(path);
}

int main(UNUSED int ac, UNUSED char **av, char **env)
{
    minishell(ac, env);
    return 0;
}
