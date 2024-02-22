/*
** EPITECH PROJECT, 2024
** navy_w_manech
** File description:
** get_line
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "my_navy.h"
#include "my.h"

pos_t get_line(void)
{
    char *buff = NULL;
    size_t len = 0;
    pos_t coords = {84, 84};
    int t = getline(&buff, &len, stdin);

    if (t == -1)
        return coords;
    if (my_strlen(buff) != 3 || !is_char_upper(buff[0])) {
        my_putstr("\nWrong position\n\nattack: ");
        return coords;
    }
    coords.x = buff[0] - 'A' + 1;
    if (buff[1] >= '0' && buff[1] <= '8')
        coords.y = my_getnbr(buff);
    if ((coords.x <= 0 || coords.x > 8) || (coords.y <= 0 || coords.y > 8)) {
        my_putstr("\nWrong position\n\nattack: ");
        coords.x = 84;
        coords.y = 84;
    }
    return coords;
}
