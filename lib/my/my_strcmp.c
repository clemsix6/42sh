/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** my_strcmp
*/

#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
    if (my_strlen(s1) != my_strlen(s2)){
        return 0;
    }
    for (int i = 0; i < my_strlen(s1); i++) {
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}
