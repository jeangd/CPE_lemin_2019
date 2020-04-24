/*
** EPITECH PROJECT, 2020
** lemin.h
** File description:
** lemin.h
*/

#ifndef LEMIN_H
#define LEMIN_H
#define UNUSED(x) (void)(x)

#include "../lib/my/my.h"
#include <stdio.h>

typedef struct room {
    char *stat;
    struct room *next;
    struct room *prev;
} room_t;

typedef struct path {
    int nbr;
    int f;
    int fourm;
    struct path *next;
    struct path *prev;
} path_t;

typedef struct all_path {
    path_t *chain;
    struct all_path *next;
    struct all_path *prev;
} all_path_t;

typedef struct addnode {
    int dest;
    int pass;
    int fourm;
    int x;
    int y;
    struct addnode *next;
} add;

typedef struct graph {
    int v;
    struct addnode **list;
} graph;


typedef struct lemin {
    char *start;
    char *end;
    int v;
    int x;
    int e;
    int y;
    int c;
    int occ;
    int fourm;
    room_t *room;
    room_t *tunnel;
    all_path_t *chain;
} lem_t;

room_t *add_list(room_t *add, char *line);
int my_str_isnum(char const *str);
int parsing_nb_ants(lem_t *);
int call_graph(lem_t *lem);
char *get_nbr(char *line);
int print_nbr(char *line);
int check_line(char *c);
int go_end(char *line, size_t nb, lem_t *lem);
int go_start(char *line, size_t nb, lem_t *lem);
room_t *make_it_double(room_t *add);
int parsing_rooms(char *line, size_t nb, lem_t *lem);
int parsing_tunnels(char *line, size_t nb, lem_t *lem);
char *my_strcpy_mod(char *dest, char const *src);
char *my_strcpy_end(char *dest, char const *src);
void get_room_nbr(lem_t *lem, char *line);
int adding_stat_to_node(lem_t *lem, graph *graph);
int my_getnbr_right(char *line);
int my_getnbr_mid(char *line);
all_path_t *add_path(all_path_t *path, graph *graph, lem_t *lem, int i);
int get_room_nbr_sec(char *line);
void print_graph(graph *graph);
int check_y(int c, lem_t *lem);
int check_x(int c, lem_t *lem);
void start_print(lem_t *lem, graph *graph, int i);
char *my_strcpy_mod_n(char *dest, char const *src);
void go_back(lem_t *lem);
void go_front(lem_t *lem);
int print_my_lem(lem_t *lem);

#endif /* !LEMIN_H */
