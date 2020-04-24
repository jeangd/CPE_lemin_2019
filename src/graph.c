/*
** EPITECH PROJECT, 2020
** lmin
** File description:
** graph creation
*/
#include "../include/lemin.h"

add *new_node(int dest, lem_t *lem)
{
    add *new = malloc(sizeof(struct addnode));
    char *s = NULL;

    new->dest = dest;
    new->next = NULL;
    new->pass = 0;
    new->fourm = 0;
    while (my_strcmp(my_itoa(dest), my_strcpy_mod(s, lem->room->stat)))
        lem->room = lem->room->next;
    new->y = my_getnbr_right(lem->room->stat);
    new->x = my_getnbr_mid(lem->room->stat);
    free(s);
    return (new);
}

graph *create_graph(int v)
{
    graph *graph = malloc(sizeof(struct graph));

    graph->v = v;
    graph->list = malloc(v * sizeof(struct addnode *));
    for (int i = 0; i < v; ++i)
        graph->list[i] = NULL;
    return (graph);
}

int add_edge(graph *graph, int src, int dest, lem_t *lem)
{
    add *new = new_node(dest, lem);

    new->next = graph->list[src];
    graph->list[src] = new;
    new = new_node(src, lem);
    new->next = graph->list[dest];
    graph->list[dest] = new;
    return (0);
}

void print_graph(graph *graph)
{
    int i = 0;

    for (i = 0; i < graph->v; i++) {
        add *node = graph->list[i];
        my_printf("\nList of vertex %d\nhead ", i);
        while (node) {
            my_printf("->%d", node->dest);
            node = node->next;
        }
        my_printf("\n");
    }
}

int call_graph(lem_t *lem)
{
    graph *graph = create_graph(lem->v + 10);
    char *first = my_strcpy(first, lem->tunnel->stat);
    char *nbr1 = my_strcpy_mod(nbr1, first);
    char *nbr2 = my_strcpy_end(nbr2, first);

    if (add_edge(graph, my_getnbr(nbr1), my_getnbr(nbr2), lem) == 84)
        return (84);
    lem->tunnel = lem->tunnel->next;
    while (my_strcmp(first, lem->tunnel->stat) != 0) {
        nbr1 = my_strcpy_mod(nbr1, lem->tunnel->stat);
        nbr2 = my_strcpy_end(nbr2, lem->tunnel->stat);
        first = my_strcpy(first, first);
        if (nbr1 != NULL && nbr2 != NULL)
            add_edge(graph, my_getnbr(nbr1), my_getnbr(nbr2), lem);
        lem->tunnel = lem->tunnel->next;
    }
    if (adding_stat_to_node(lem, graph) == 84)
        return (84);
    return (0);
}
