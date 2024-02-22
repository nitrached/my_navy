/*
** EPITECH PROJECT, 2023
** Day04-Pointers
** File description:
** Task05 - turn a string into a int
*/
#include "my.h"
#include <stdio.h>

int my_isnumber(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int calcul(char const *str)
{
    int n = 0;
    int len = my_strlen(str) - 1;
    int mul = 1;

    for (int i = len; i >= 0; i--) {
        if (my_isnumber(str[i]) == 1) {
            n += (str[i] - 48) * mul;
            mul = mul * 10;
        }
    }
    return n;
}

int get_size(char const *str)
{
    int size = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_isnumber(str[i]) == 0)
            continue;
        if (my_isnumber(str[i + 1]) == 0) {
            size++;
            break;
        }
        size++;
    }
    return size;
}

int my_getnbr(char const *str)
{
    int res_calcul = 0;
    int size = get_size(str);
    int mul = my_compute_power_rec(10, size - 1);

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_isnumber(str[i]) == 0)
            continue;
        if (my_isnumber(str[i + 1]) == 0) {
            res_calcul += (str[i] - 48) * mul;
            mul = mul / 10;
            break;
        }
        res_calcul += (str[i] - 48) * mul;
        mul = mul / 10;
    }
    return res_calcul;
}
