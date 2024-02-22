/*
** EPITECH PROJECT, 2024
** navy_w_manech
** File description:
** send_signal
*/
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "my_navy.h"

int send_signal(SIGNAL_e signal, int pid)
{
    unsigned char bit = 0;

    for (int i = 7; i >= 0; i--) {
        bit = (signal >> i) & 1;
        kill(pid, bit ? SIGUSR2 : SIGUSR1);
        usleep(10000);
    }
    return signal;
}
