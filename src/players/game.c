/*
** EPITECH PROJECT, 2024
** navy_w_manech
** File description:
** game
*/
#include "my_navy.h"
#include "my.h"

int game(char **map_self, char **map_enemy, int player)
{
    pos_t coords;

    while (1) {
        if (win_lose(map_self, map_enemy, player))
            return 0;
        play(&coords);
        handle_coords(map_self, map_enemy, player);
        miss_hit(&coords, map_self, map_enemy, player);
    }
    return 1;
}
