/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** my_putstr
*/

#include "my.h"

void my_putstr(const char *str)
{
    write(1, str, my_strlen(str));
}
