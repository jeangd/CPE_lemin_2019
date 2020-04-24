/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** check distance
*/
#include "../include/lemin.h"

int check_x(int c, lem_t *lem)
{
    while (c != get_room_nbr_sec(lem->room->stat))
        lem->room = lem->room->next;
    return (my_getnbr_mid(lem->room->stat));
}

int check_y(int c, lem_t *lem)
{
    while (c != get_room_nbr_sec(lem->room->stat))
        lem->room = lem->room->next;
    return (my_getnbr_right(lem->room->stat));
}
