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
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>


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
    int client_fd;
    struct sockaddr_in serv_addr;
    char *command = "P2_CONECTED";

    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr);
    connect(client_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    send(client_fd, command, strlen(command), 0);
    while (1) {
        if (condition_player_2(map_self, map_enemy) == 1)
            return 0;
    }
    return 1;
}
