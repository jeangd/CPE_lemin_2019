/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** foumiz pass
*/
#include "../include/lemin.h"

void help_mouv(lem_t *lem, int total)
{
    for (; lem->chain->chain->prev;
        lem->chain->chain = lem->chain->chain->prev) {
        lem->chain->chain->f = lem->chain->chain->prev->f;
        if (lem->chain->chain->prev->nbr == get_room_nbr_sec(lem->start)) {
            lem->chain->chain->f = total - lem->fourm;
            lem->fourm--;
        }
    }
}

void help_finish(lem_t *lem)
{
    for (; lem->chain->chain->prev;
        lem->chain->chain = lem->chain->chain->prev) {
        lem->chain->chain->f = lem->chain->chain->prev->f;
        if (lem->chain->chain->prev->nbr == get_room_nbr_sec(lem->start)) {
            lem->chain->chain->f = 0;
        }
    }
}

int make_mouv(lem_t *lem, graph *graph, int i, int total)
{
    path_t *path = NULL;
    total++;

    go_back(lem);
    while (1) {
        go_front(lem);
        help_mouv(lem, total);
        go_front(lem);
        path = lem->chain->chain;
        if (lem->chain->next == NULL) {
            print_my_lem(lem);
            return (lem->fourm);
        } lem->chain = lem->chain->next;
    }
}

void finish_it(lem_t *lem)
{
    path_t *path = NULL;

    go_back(lem);
    while (lem->chain->chain->f != 0) {
        go_front(lem);
        help_finish(lem);
        go_front(lem);
        path = lem->chain->chain;
        if (lem->chain->next == NULL && lem->chain->chain->f != 0) {
            print_my_lem(lem);
            for (; lem->chain->prev; lem->chain = lem->chain->prev);
            my_printf("\n");
        } else if (lem->chain->chain->f != 0)
            lem->chain = lem->chain->next;
    }
}

void start_print(lem_t *lem, graph *graph, int i)
{
    int total = lem->fourm;

    while (lem->fourm > 0) {
        lem->fourm = make_mouv(lem, graph, i, total);
        my_printf("\n");
    }
    finish_it(lem);
}
