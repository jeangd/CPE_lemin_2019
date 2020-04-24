/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** chain list help
*/
#include "../include/lemin.h"

void go_back(lem_t *lem)
{
    for (; lem->chain->prev; lem->chain = lem->chain->prev);
}

void go_front(lem_t *lem)
{
    while (lem->chain->chain->next)
        lem->chain->chain = lem->chain->chain->next;
}
