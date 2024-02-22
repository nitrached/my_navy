/*
** EPITECH PROJECT, 2024
** navy
** File description:
** fill_struct
*/
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "my_navy.h"
#include <stdlib.h>
#include "my.h"

static int start_is_more_than_end(navy_t *ship)
{
    if (ship->data->pos_start->x == ship->data->pos_end->x &&
        ship->data->pos_start->y > ship->data->pos_end->y) {
        if ((ship->data->pos_start->y - ship->data->pos_end->y) + 1 !=
            ship->data->len_boat)
            return 84;
    }
    if (ship->data->pos_start->y == ship->data->pos_end->y &&
        ship->data->pos_start->x > ship->data->pos_end->x) {
        if ((ship->data->pos_start->x - ship->data->pos_end->x) + 1 !=
            ship->data->len_boat)
            return 84;
    }
    return 0;
}

static int start_is_less_than_end(navy_t *ship)
{
    if (ship->data->pos_start->x == ship->data->pos_end->x &&
        ship->data->pos_start->y < ship->data->pos_end->y) {
        if ((ship->data->pos_end->y - ship->data->pos_start->y) + 1 !=
            ship->data->len_boat)
            return 84;
    }
    if (ship->data->pos_start->y == ship->data->pos_end->y &&
        ship->data->pos_start->x < ship->data->pos_end->x) {
        if ((ship->data->pos_end->x - ship->data->pos_start->x) + 1 !=
            ship->data->len_boat)
            return 84;
    }
    return 0;
}

int fill_struct(char **individual_info, navy_t *ship)
{
    if (individual_info == NULL || ship == NULL)
        return 84;
    if (my_strlen(individual_info[0]) != 1 || my_strlen(individual_info[1])
        != 2 || my_strlen(individual_info[2]) != 2)
        return 84;
    if (individual_info[1][0] != individual_info[2][0] && individual_info[1][1]
        != individual_info[2][1])
        return 84;
    ship->data->len_boat = my_getnbr(individual_info[0]);
    ship->data->pos_start->x = individual_info[1][0] - 65;
    ship->data->pos_start->y = individual_info[1][1] - 48 - 1;
    ship->data->pos_end->x = individual_info[2][0] - 65;
    ship->data->pos_end->y = individual_info[2][1] - 48 - 1;
    if (start_is_less_than_end(ship) == 84 ||
        start_is_more_than_end(ship) == 84)
        return 84;
    if (ship->data->pos_start->x == ship->data->pos_end->x &&
        ship->data->pos_start->y == ship->data->pos_end->y)
        return 84;
    return 0;
}
