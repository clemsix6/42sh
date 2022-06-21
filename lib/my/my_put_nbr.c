/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** my_put_nbr
*/

#include "my.h"

void my_put_nbr(int nb)
{
    int d = 0;

    if (nb < 0) {
        my_putchar('-');
        if (nb == -2147483648) {
            my_putchar('2');
            nb = nb + 2000000000;
        }
        nb = - nb;
    }
    if (nb == 10)
        my_putchar('1');
    d = nb % 10;
    if (nb > 10)
        my_put_nbr(nb / 10);
    my_putchar(d + 48);
}
