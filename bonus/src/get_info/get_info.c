/*
** EPITECH PROJECT, 2024
** navy
** File description:
** get_info
*/
#include "my_navy.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "my.h"
#include <string.h>

static char *condition(int file, char *content, int *contentSize)
{
    char buffer[4096];
    char *temp = NULL;
    int bytesread = read(file, buffer, sizeof(buffer));

    while (bytesread > 0) {
        temp = malloc(*contentSize + bytesread + 1);
        if (content) {
            memcpy(temp, content, *contentSize);
            free(content);
        }
        content = temp;
        memcpy(content + *contentSize, buffer, bytesread);
        *contentSize += bytesread;
        bytesread = read(file, buffer, sizeof(buffer));
    }
    return content;
}

static char *open_file(const char *filename)
{
    int file = open(filename, O_RDONLY);
    char *content = NULL;
    int contentSize = 0;

    content = condition(file, content, &contentSize);
    close(file);
    if (content)
        content[contentSize] = '\0';
    return content;
}

static int is_enought_arg(char **info)
{
    int i = 0;

    while (info[i] != NULL)
        i++;
    return i;
}

static int check_between_2_5(char *info, navy_t *ship)
{
    char **individual_info = my_str_to_word_array(info, ":");

    if (individual_info == NULL || individual_info[0] == NULL)
        return 84;
    if (my_getnbr(individual_info[0]) >= 2 && my_getnbr(individual_info[0])
        <= 5) {
        if (is_enought_arg(individual_info) != 3) {
            free_tab(individual_info);
            return 84;
        }
        if (fill_struct(individual_info, ship) == 84)
            return 84;
        free_tab(individual_info);
        return 0;
    }
    free_tab(individual_info);
    return 84;
}

static int check_tab(navy_t **tab, int i)
{
        for (int j = 0; tab[j] != NULL; j++) {
            if (tab[i]->data->len_boat == tab[j]->data->len_boat && i != j)
                return 84;
        }
    return 0;
}

int get_info(char const *filepath, navy_t **tab)
{
    char *arg = open_file(filepath);
    char **info = my_str_to_word_array(arg, "\n");

    if (info == NULL || tab == NULL || is_enought_arg(info) != 4)
        return 84;
    for (int i = 0; info[i] != NULL; i++) {
        if (check_between_2_5(info[i], tab[i]) == 84) {
            free_tab(info);
            return 84;
        }
    }
    for (int i = 0; tab[i] != NULL; i++) {
        if (check_tab(tab, i) == 84)
            return 84;
    }
    free(arg);
    free_tab(info);
    return 0;
}
