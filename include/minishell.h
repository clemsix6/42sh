/*
** EPITECH PROJECT, 2022
** minishell.h
** File description:
** minishell.h
*/

#ifndef h_minishell
    #define h_minishell
    #define UNUSED __attribute__((unused))
    #include <stdbool.h>
    #include "my.h"

typedef struct binary_tree_s
{
    char *str;
    char *operator;
    char *command;
    struct binary_tree_s *right;
    struct binary_tree_s *left;
}binary_tree_t;

typedef struct node_s
{
    char *str;
    struct node_s *next;
} node_t;

int my_strlen_shell(char const *str);
char **parse_path(char *env);
void exec_condition(char *link_folder, char **args, char **env);
int exec(char *cmd, char **args, char **env, char **path);
int link_exec(char *cmd, char **args, char **env);
int search_index(char *str);
char *take_left(char *str, int index);
int count_right(char *str, int index);
bool have_semicolon(char *cmd);
int have_redirect(char *cmd);
bool have_pipe(char *cmd);
char *setenv_name(char *dest, char *src);
int size_ll(llist list);
char **ll_to_env(llist ll_env);
llist env_to_ll(char **env);
char *take_right(char *str, int index);
void print_binary(binary_tree_t *tree);
llist env_to_ll(char **env);
int execution(char **av, char **env, char **path);
llist my_echo(int argc, char **argv, llist env);
void print_env(char **env);
char *build_link_folder(char **path, int i, char *cmd);
int search_path(char **env);
char *my_strtok(char *env, char delimiter);
binary_tree_t *init_node(void);
binary_tree_t *build_tree_node(binary_tree_t *tree, char *str);
int comt(char *arg);
llist my_exit(int ac, char **argv UNUSED, llist env UNUSED);
int exec_with_redirect(char *cmd, int ac, char **env, char **path);
void print_binary(binary_tree_t *tree);
llist my_cd(int ac, char **argv UNUSED, llist env UNUSED);
llist my_setenv(int ac, char **argv UNUSED, llist env UNUSED);
int exec_with_pipe(char *cmd, int ac, char **env, char **path);
llist my_unsetenv(int ac, char **argv UNUSED, llist env UNUSED);
llist my_env(int ac, char **argv UNUSED, llist env UNUSED);
llist get_builtin(int ac, char *name, char **av, llist env);
char *initialize(char *str);
char **mem_2d_array(int size);
char **parse_command(char *arg, char *separator);
bool search_old_pwd(char *str);
bool search_pwd(char *str);
int is_old_pdw(char *tok);
int pdw(char *tok);
int my_strlen_of2darray(char **str);
llist set_pwd(llist env, char pwd[1024]);
int is_in_path(char **env, char *name);
bool have_double_esperluette(char *cmd);
bool have_double_pipe(char *cmd);

#endif
