/*
** EPITECH PROJECT, 2024
** navy
** File description:
** free_all
*/
#include "my_navy.h"
#include <stdlib.h>

int free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        free(tab[i]);
    }
    free(tab);
    return 0;
}

int free_all(navy_t **tab, char **map)
{
    for (int i = 0; i < 4; i++) {
        free(tab[i]->data->pos_start);
        free(tab[i]->data->pos_end);
        free(tab[i]->data);
        free(tab[i]);
    }
    for (int i = 0; i < 8; i++)
        free(map[i]);
    free(map);
    free(tab);
    return 0;
}
