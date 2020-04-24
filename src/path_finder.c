/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** find path
*/
#include "../include/lemin.h"

path_t *add_chain_path(path_t *path, int nbr)
{
    path_t *new = malloc(sizeof(path_t));
    path_t *tmp;

    new->nbr = nbr;
    new->f = 0;
    new->next = NULL;
    new->prev = NULL;
    new->fourm = 0;
    if (!path) {
        new->f = 1;
        return (new);
    } tmp = path;
    while (tmp->next != NULL) {
        tmp->next->prev = tmp;
        tmp = tmp->next;
    } tmp->next = new;
    tmp->next->prev = tmp;
    return (path);
}

all_path_t *add_path(all_path_t *path, graph *graph, lem_t *lem, int i)
{
    add *check = graph->list[i];
    add *node = graph->list[i];

    for (int c = i; check; node = graph->list[c]) {
        while (node) {
            if (node->dest == get_room_nbr_sec(lem->end) ||
                c == get_room_nbr_sec(lem->end)) {
                graph->list[c]->pass = 1;
                path->chain = add_chain_path(path->chain, c);
                if (node->dest == get_room_nbr_sec(lem->end))
                    path->chain = add_chain_path(path->chain, node->dest);
                return (path);
            } node = node->next;
        } if (graph->list[check->dest]->pass == 0) {
            graph->list[c]->pass = 1;
            path->chain = add_chain_path(path->chain, c);
            c = check->dest;
            check = graph->list[check->dest];
        } else
            check = check->next;
    }
    return (NULL);
}
