/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** my_strlen_of2darray.c
*/

#include "my.h"

int my_strlen_of2darray(char **str)
{
    int result = 0;
    while (str[result] != NULL) {
        result++;
    }
    return result;
}
