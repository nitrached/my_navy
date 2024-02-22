/*
** EPITECH PROJECT, 2024
** navy_w_manech
** File description:
** player_2
*/
#include "my_navy.h"
#include "my.h"
#include <sys/types.h>
#include <unistd.h>

static int condition_player_2(char **map_self, char **map_enemy)
{
    if (global.count == 8 && global.signal_value == P1_READY) {
            my_putstr("successfully connected\n\n");
            print_map(map_self, map_enemy);
            global.count = 0;
            global.signal_value = 0;
            send_signal(PLAY, global.pid);
            my_putstr("waiting for enemy's attack...\n\n");
            game(map_self, map_enemy, 2);
        }
    if (global.victory == 1 || global.victory == -1)
        return 1;
    return 0;
}

int player_2(char **map_self, char **map_enemy, char const *pid)
{
    pid_t process_id = getpid();

    global.signal_value = 0;
    global.count = 0;
    global.victory = 0;
    global.pid = my_getnbr(pid);
    my_printf("my_pid: %d\n\n", process_id);
    send_signal(P2_CONECTED, global.pid);
    while (1) {
        if (condition_player_2(map_self, map_enemy) == 1)
            return 0;
    }
    return 1;
}
