/*
** EPITECH PROJECT, 2022
** add_back
** File description:
** add_back
*/

#include "my.h"

llist add_back(llist liste, char *valeur)
{
    element* nouvelElement = malloc(sizeof(element));
    nouvelElement->val = valeur;
    nouvelElement->nxt = NULL;
    if (liste == NULL) {
        return nouvelElement;
    } else {
        element* temp = liste;
        while (temp->nxt != NULL) {
            temp = temp->nxt;
        }
        temp->nxt = nouvelElement;
        return liste;
    }
}
