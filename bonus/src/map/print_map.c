/*
** EPITECH PROJECT, 2024
** navy_w_manech
** File description:
** print_map
*/
#include <stddef.h>
#include "my_navy.h"
#include "my.h"

void print_lines(char **map, int i)
{
    for (int j = 0; map[i][j] != '\0'; j++) {
        my_putchar(map[i][j]);
        if (map[i][j + 1] != '\0')
            my_putchar(' ');
    }
}

void print_map(char **map, char **map_enemy)
{
    my_putstr("my navy:\n");
    my_putstr(" |A B C D E F G H\n-+----------------\n");
    for (int i = 0; map[i] != NULL; i++) {
        my_printf("%d|", (i + 1));
        print_lines(map, i);
    }
    my_putstr("\n\nenemy navy:\n");
    my_putstr(" |A B C D E F G H\n-+----------------\n");
    for (int i = 0; map_enemy[i] != NULL; i++) {
        my_printf("%d|", (i + 1));
        print_lines(map_enemy, i);
    }
    my_putstr("\n");
}
