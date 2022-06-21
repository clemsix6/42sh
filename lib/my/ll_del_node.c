/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** delnode
*/

#include "my.h"

llist supprimerElement(llist list, char *valeur)
{
    char *tok = NULL;
    llist tmp;
    llist previous;
    if (list == NULL)
        return (list);
    previous = list;
    tok = strtok(strdup(previous->val), "=");
    if (strcmp(tok, valeur) == 0) {
        list = previous->nxt;
        free(previous);
        return (list);
    }
    tmp = previous->nxt;
    while (tmp != NULL) {
        tok = strtok(strdup(previous->val), "=");
        if (strcmp(tok, valeur) == 0) {
            previous->nxt = tmp->nxt;
            free(previous);
            return (list);
        }
        previous = tmp;
        tmp = tmp->nxt;
    }
    return list;
}
