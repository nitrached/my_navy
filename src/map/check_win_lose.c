/*
** EPITECH PROJECT, 2024
** navy_w_manech
** File description:
** check_win_lose
*/
#include <stddef.h>
#include "my.h"
#include "my_navy.h"

static int condition_map(char **map, int i, int j, int *cpt)
{
    if (map[i][j] == 'x')
        (*cpt)++;
    return 0;
}

int check_win_lose_loop(char **map, int *cpt)
{
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++)
            condition_map(map, i, j, cpt);
    }
    return 0;
}

int check_win_lose(char **map_self, char **map_enemy)
{
    int cpt = 0;

    check_win_lose_loop(map_self, &cpt);
    if (cpt >= 14) {
        global.victory = -1;
        return 0;
    }
    cpt = 0;
    check_win_lose_loop(map_enemy, &cpt);
    if (cpt >= 14) {
        global.victory = 1;
        return 0;
    }
    return 1;
}
