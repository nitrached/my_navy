/*
** EPITECH PROJECT, 2024
** navy_w_manech
** File description:
** signal_handler
*/
#include "my_navy.h"
#include <unistd.h>
#include <sys/types.h>

void signal_handler(int sig, siginfo_t *siginfo, void *panic)
{
    (void)panic;
    if (global.pid == -1)
        global.pid = siginfo->si_pid;
    if (sig == SIGUSR1) {
        global.count++;
        global.signal_value = (global.signal_value << 1) | 0;
    }
    if (sig == SIGUSR2) {
        global.count++;
        global.signal_value = (global.signal_value << 1) | 1;
    }
}
