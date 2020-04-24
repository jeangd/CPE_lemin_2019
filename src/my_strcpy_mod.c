/*
** EPITECH PROJECT, 2020
** my_strcpy_mod.c
** File description:
** my_strcpy_mod.c
*/

#include "../include/lemin.h"

char *my_strcpy_end(char *dest, char const *src)
{
    int j = 0;
    int i = 0;

    dest = malloc(sizeof(char) * my_strlen(src) + 1);
    if (dest == NULL)
        return (NULL);
    for (j = 0; src[j] != '\0' && src[j] != '-'; j++);
    j++;
    for (int i = 0; src[j] != '\0' && src[j] != '\n'; j++, i++)
        dest[i] = src[j];
    dest[i + 1] = '\0';
    return (dest);
}

char *my_strcpy_mod(char *dest, char const *src)
{
    int j;

    dest = malloc(sizeof(char) * my_strlen(src) + 1);
    if (dest == NULL)
        return (NULL);
    for (j = 0; src[j] != '\0' && src[j] != ' ' && src[j] != '-'; j++)
        dest[j] = src[j];
    dest[j] = '\0';
    return (dest);
}

void get_room_nbr(lem_t *lem, char *line)
{
    char *nbr = malloc(sizeof(char) * my_strlen(line));
    int i = 0;

    for (; line[i] != '\0' && line[i] != ' '; i++)
        nbr[i] = line[i];
    nbr[i] = '\0';
    if (lem->v < my_getnbr(nbr));
        lem->v = my_getnbr(nbr);
    free(nbr);
}

int get_room_nbr_sec(char *line)
{
    char *nbr = malloc(sizeof(char) * (my_strlen(line) + 1));
    int i = 0;

    for (; line[i] != '\0' && line[i] != ' '; i++)
        nbr[i] = line[i];
    nbr[i] = '\0';
    return (my_getnbr(nbr));
}

char *my_strcpy_mod_n(char *dest, char const *src)
{
    int j;

    dest = malloc(sizeof(char) * my_strlen(src) + 1);
    if (dest == NULL)
        return (NULL);
    for (j = 0; src[j] != '\0' && src[j] != '\n' && src[j] != '#'; j++)
        dest[j] = src[j];
    dest[j] = '\0';
    return (dest);
}