/*
** EPITECH PROJECT, 2023
** int to char
** File description:
** convert a int into a char *
*/

#include <stdio.h>
#include <stdlib.h>

char *int_to_char(int number)
{
    int temp = number;
    int size = 0;
    char *result = NULL;

    while (temp != 0) {
        temp /= 10;
        size++;
    }
    if (number == 0)
        size = 1;
    result = malloc(sizeof(char) * (size + 1));
    for (int i = size - 1; i >= 0; i--) {
        result[i] = '0' + (number % 10);
        number /= 10;
    }
    result[size] = '\0';
    return result;
}
