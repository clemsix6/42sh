/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_memcpy
*/

#include "my.h"

char *my_memcpy(char *dest, const char *src, size_t len)
{
    char *destination = dest;
    const char *source = src;
    while (len--) {
        *destination++ = *source++;
    }
    return dest;
}
