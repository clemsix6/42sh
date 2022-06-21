/*
** EPITECH PROJECT, 2022
** add_front
** File description:
** add_front
*/

#include "my.h"

llist add_front(llist liste, char *valeur)
{
    element* nouvelElement = malloc(sizeof(element));
    nouvelElement->val = valeur;
    nouvelElement->nxt = liste;
    return nouvelElement;
}
