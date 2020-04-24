/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** print kem
*/
#include "../include/lemin.h"

void go_back_one_node(lem_t *lem)
{
    for (; lem->chain->next; lem->chain = lem->chain->next)
        if (lem->chain->chain->prev != NULL)
            lem->chain->chain = lem->chain->chain->prev;
    lem->chain->chain = lem->chain->chain->prev;
}

int check_all_list(lem_t *lem)
{
    all_path_t *all = lem->chain;

    for (; all; all = all->next)
        if (all->chain->prev != NULL)
            return (0);
    return (1);
}

void print_my_graph(lem_t *lem, int i, path_t *path)
{
    for (; lem->chain->next; lem->chain = lem->chain->next) {
        if (path->f != 0 && path->nbr != get_room_nbr_sec(lem->start)
            && i != 0)
            my_printf(" P%d-%d", path->f, path->nbr);
        else if (path->f != 0 && path->nbr != get_room_nbr_sec(lem->start)
            && i == 0) {
            my_printf("P%d-%d ", path->f, path->nbr);
            i++;
        }
        path = lem->chain->chain;
    }
}

int print_my_lem(lem_t *lem)
{
    all_path_t *all = lem->chain;
    path_t *path = NULL;
    int i = 0;

    while (check_all_list(lem) == 0) {
        path = lem->chain->chain;
        print_my_graph(lem, i, path);
        path = lem->chain->chain;
        if (path->f != 0 && path->nbr != get_room_nbr_sec(lem->start)) {
            my_printf("P%d-%d", path->f, path->nbr);
        if (path->prev->f != 0
            && path->prev->nbr != get_room_nbr_sec(lem->start))
            my_printf(" ");
        }
        go_back(lem);
        go_back_one_node(lem);
        go_back(lem);
        path = lem->chain->chain;
    }
}
