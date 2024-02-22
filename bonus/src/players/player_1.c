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
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

static int condition_player_1(char **map_self, char **map_enemy, char *buff, int n, int newsockfd)
{
    bzero(buff, 255);
    n = read(newsockfd, buff, 255);
    if (my_strcmp(buff, "P2_CONECTED") == 0) {
            print_map(map_self, map_enemy);
            /* global.count = 0;
            global.signal_value = 0;
            send_signal(P1_READY, global.pid);
            game(map_self, map_enemy, 1); */
        }
    if (global.victory == 1 || global.victory == -1)
        return 1;
    return 0;
}

int player_1(char **map_self, char **map_enemy, char *argv[])
{
    int sockfd, newsockfd , portnbr, n;
    char buff[255];
    struct sockaddr_in server_addr, cli_addr;
    socklen_t clilen;
    int i;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *) &server_addr, sizeof(server_addr));
    portnbr = atoi(argv[1]);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(portnbr);
    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
        error("biniding failed\n");
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    my_putstr("\n\nwaiting for enemy connection...\n\n");
    while (1) {
        if (condition_player_1(map_self, map_enemy, buff, n, newsockfd) == 1)
            return 0;
    }
    return 1;
}
