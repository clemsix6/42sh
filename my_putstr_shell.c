/*
** EPITECH PROJECT, 2022
** putstr shell
** File description:
** putstr shell
*/

#include "include/my.h"
#include "include/minishell.h"

void my_putstr_shell(const char *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar(str[i]);
        i++;
    }
}
