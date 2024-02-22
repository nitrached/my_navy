/*
** EPITECH PROJECT, 2024
** navy_w_manech
** File description:
** win_lose
*/
#include "my.h"
#include "my_navy.h"

static int condition_win_lose(char **map_self, char **map_enemy, int player)
{
    if (global.victory == 1) {
            print_map(map_self, map_enemy);
            my_putstr("I won\n");
            return 1;
        }
        if (global.victory == -1) {
            if (player == 2)
                print_map(map_self, map_enemy);
            my_putstr("enemy won\n");
            return 1;
        }
    return 0;
}

int win_lose(char **map_self, char **map_enemy, int player)
{
    if (!check_win_lose(map_self, map_enemy)) {
        condition_win_lose(map_self, map_enemy, player);
    }
    return 0;
}
