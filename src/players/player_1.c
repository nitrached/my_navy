/*
** EPITECH PROJECT, 2024
** navy_w_manech
** File description:
** player_1
*/
#include "my.h"
#include "my_navy.h"
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

static int condition_player_1(char **map_self, char **map_enemy)
{
    if (global.count == 8 && global.signal_value == P2_CONECTED) {
            my_putstr("enemy connected\n\n");
            print_map(map_self, map_enemy);
            global.count = 0;
            global.signal_value = 0;
            send_signal(P1_READY, global.pid);
            game(map_self, map_enemy, 1);
        }
    if (global.victory == 1 || global.victory == -1)
        return 1;
    return 0;
}

int player_1(char **map_self, char **map_enemy)
{
    pid_t process_id = getpid();

    global.signal_value = 0;
    global.count = 0;
    global.pid = -1;
    global.victory = 0;
    my_putstr("my_pid: ");
    my_put_nbr(process_id);
    my_putstr("\n\nwaiting for enemy connection...\n\n");
    while (1) {
        if (condition_player_1(map_self, map_enemy) == 1)
            return 0;
    }
    return 1;
}
