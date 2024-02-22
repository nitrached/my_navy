/*
** EPITECH PROJECT, 2024
** navy
** File description:
** main
*/
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "my_navy.h"
#include <stdlib.h>
#include "my.h"

global_value_t global;

int print_dash_h(void)
{
    my_putstr("USAGE :\n ./cmd [file] for player 1\n");
    my_putstr(" ./cmd [signal] [file] for player 2\n");
    return 0;
}

int init_map(char **map, navy_t **tab, char const *argv)
{
    if (get_info(argv, tab) == 84)
        return 84;
    if (get_map(tab, map) == 84)
        return 84;
    return 0;
}

int my_navy(int argc, char const **argv, navy_t **tab)
{
    char **map_self = innit_map();
    char **map_enemy = innit_map();

    if (argc == 2) {
        if (init_map(map_self, tab, argv[1]) == 84)
            return 84;
        player_1(map_self, map_enemy);
    }
    if (argc == 3) {
        if (init_map(map_self, tab, argv[2]) == 84)
            return 84;
        player_2(map_self, map_enemy, argv[1]);
    }
    free_all(tab, map_self);
    return 0;
}


int main(int argc, char const **argv)
{
    struct sigaction act;
    navy_t **tab = innit_tab();

    if (argc < 2 || argc > 3) {
        my_putstr("invalid number of parameter,\ntry ./[binary] -h\n");
        return 84;
    }
    if (argc == 2 && !my_strcmp(argv[1], "-h"))
        return print_dash_h();
    act.sa_sigaction = signal_handler;
    act.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &act, NULL) < 0
        || sigaction(SIGUSR2, &act, NULL) < 0)
        return 84;
    if (my_navy(argc, argv, tab) == 84)
        return 84;
    return 0;
}
