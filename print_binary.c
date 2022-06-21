/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** print_binary.c
*/

#include "include/minishell.h"
#include "include/my.h"

void print_binary(binary_tree_t *tree)
{
    if (tree == NULL) {
        return;
    }
    if (tree->command != NULL) {
        my_putstr("command :");
        my_putstr(tree->command);

    }
    if (tree->operator != NULL) {
        my_putstr("operator :");
        my_putstr(tree->operator);
    }
    my_putstr("\n");
    print_binary(tree->left);
    print_binary(tree->right);
}
