/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** finding different path
*/
#include "../include/lemin.h"

all_path_t *create_new_node(all_path_t *path)
{
    all_path_t *new = malloc(sizeof(all_path_t));
    all_path_t *tmp;

    new->chain = NULL;
    new->next = NULL;
    new->prev = NULL;
    if (!path)
        return (new);
    tmp = path;
    while (tmp->next != NULL) {
        tmp->next->prev = tmp;
        tmp = tmp->next;
    } tmp->next = new;
    tmp->next->prev = tmp;
    return (path);
}

int is_finished(lem_t *lem, graph *graph, int i)
{
    add *check = graph->list[i];

    while (check) {
        if (graph->list[check->dest]->pass == 0)
            return (0);
        check = check->next;
    }
    free(check);
    return (1);
}

int adding_stat_to_node(lem_t *lem, graph *graph)
{
    int i = 0;
    int z = 0;
    char *str = my_strcpy_mod(str, lem->start);

    lem->chain = NULL;
    i = get_room_nbr_sec(lem->start);
    lem->x = my_getnbr_mid(lem->end);
    lem->y = my_getnbr_right(lem->end);
    while (is_finished(lem, graph, i) == 0) {
        lem->chain = create_new_node(lem->chain);
        if (z != 0)
            lem->chain = lem->chain->next;
        lem->chain = add_path(lem->chain, graph, lem, i);
        graph->list[i]->pass = 0;
        lem->occ++;
        z++;
    }
    if (lem->chain == NULL)
        return (84);
    my_printf("#moves\n");
    start_print(lem, graph, i);
}
