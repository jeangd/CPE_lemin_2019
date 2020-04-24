/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include "../include/lemin.h"

void display_h(void)
{
    my_printf("usage : gmin.pl size density nb_of_fourmiz\n");
    my_printf("When size is the number of rooms and density ");
    my_printf("the percentage of probability of connexions between rooms\n");
}

int main(void)
{
    lem_t *lem = malloc(sizeof(lem_t));

    lem->start = NULL;
    lem->end = NULL;
    lem->v = 0;
    lem->occ = 0;
    if (parsing_nb_ants(lem) == 84)
        return (84);
    return (0);
}
