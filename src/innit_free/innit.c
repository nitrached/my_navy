/*
** EPITECH PROJECT, 2024
** navy
** File description:
** innit
*/
#include "my_navy.h"
#include <stdlib.h>

char **innit_map(void)
{
    char **map = malloc(sizeof(char *) * (8 + 1));

    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(char) * (8 + 2));
        for (int j = 0; j < 8; j++) {
            map[i][j] = '.';
        }
        map[i][8] = '\n';
        map[i][9] = '\0';
    }
    map[8] = NULL;
    return map;
}

navy_t **innit_tab(void)
{
    navy_t **navy = malloc(sizeof(navy_t *) * (4 + 1));

    for (int i = 0; i < 4; i++) {
        navy[i] = malloc(sizeof(navy_t));
        navy[i]->data = malloc(sizeof(data_t));
        navy[i]->data->pos_start = malloc(sizeof(pos_t));
        navy[i]->data->pos_end = malloc(sizeof(pos_t));
        navy[i]->data->is_touched = 0;
        navy[i]->data->pos_start->x = 0;
        navy[i]->data->pos_start->y = 0;
        navy[i]->data->pos_end->x = 0;
        navy[i]->data->pos_end->y = 0;
        navy[i]->data->len_boat = 0;
    }
    navy[4] = NULL;
    return navy;
}
