/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** room parsing
*/
#include "../include/lemin.h"

int my_getnbr_mid(char *line)
{
    char *new = malloc(sizeof(char) * my_strlen(line));
    int i = 0;
    int x = 0;

    for (; line[i] != ' '; i++);
    i++;
    for (; line[i] != ' ' && line[i] != '\0'; i++) {
        new[x] = line[i];
        x++;
    }
    new[x] = '\0';
    return (my_getnbr(new));
}

int my_getnbr_right(char *line)
{
    char *new = malloc(sizeof(char) * my_strlen(line));
    int i = 0;
    int x = 0;

    for (; line[i] != ' '; i++);
    i++;
    for (; line[i] != ' '; i++);
    i++;
    for (; line[i] != ' ' && line[i] != '\0'; i++) {
        new[x] = line[i];
        x++;
    }
    new[x] = '\0';
    return (my_getnbr(new));
}

int parsing_rooms(char *line, size_t nb, lem_t *lem)
{
    my_printf("#rooms\n");
    while (getline(&line, &nb, stdin) > -1 && line[1] != '-') {
        if (check_line(line) == 84) return (84);
        if (my_strcmp(line, "##start\n") == 0) {
            getline(&line, &nb, stdin);
            if (go_start(line, nb, lem) == 84) return (84);
        }
        else if (my_strcmp(line, "##end\n") == 0) {
            getline(&line, &nb, stdin);
            if (go_end(line, nb, lem) == 84) return (84);
        }
        else {
            lem->room = add_list(lem->room, line);
            get_room_nbr(lem, line);
            print_nbr(line);
        }
    }
    if (line[1] == '-')
        lem->tunnel = add_list(lem->tunnel, line);
}
