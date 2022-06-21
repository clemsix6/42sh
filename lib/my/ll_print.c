/*
** EPITECH PROJECT, 2022
** ll_print
** File description:
** print_list
*/

#include "my.h"

void print_list(llist liste)
{
    element *tmp = liste;
    while (tmp != NULL) {
        my_putstr(tmp->val);
        tmp = tmp->nxt;
    }
}
