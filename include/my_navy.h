/*
** EPITECH PROJECT, 2024
** navy
** File description:
** my_navy
*/

#ifndef MY_NAVY_H_
    #define MY_NAVY_H_
    #include <signal.h>

typedef struct pos_s {
    int x;
    int y;
} pos_t;

typedef struct data_s {
    pos_t *pos_start;
    pos_t *pos_end;
    int is_touched;
    int len_boat;
} data_t;

typedef struct navy_s {
    data_t *data;
} navy_t;

typedef struct global_value_s {
    unsigned char signal_value;
    char count;
    int pid;
    char victory;
} global_value_t;

typedef enum SIGNAL_s {
    ONE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    P2_CONECTED = 9,
    P1_READY = 10,
    PLAY = 11,
    HIT = 12,
    MISS = 13,
    WIN = 14,
    LOSE = 15
} SIGNAL_e;

extern global_value_t global;

//innit and free
navy_t **innit_tab(void);
char **innit_map(void);
int free_all(navy_t **tab, char **map);
int free_tab(char **tab);

//get info
int get_info(char const *filepath, navy_t **tab);
int fill_struct(char **individual_info, navy_t *tab);
int get_map(navy_t **tab, char **map);

//signal handler
void signal_handler(int sig, siginfo_t *siginfo, void *panic);
int send_signal(SIGNAL_e signal, int pid);
int play(pos_t *coords);
int miss_hit(pos_t *coords, char **map, char **map_enemy, int player);
int handle_coords(char **map, char **map_enemy, int player);
int game(char **map_self, char **map_enemy, int player);
int win_lose(char **map_self, char **map_enemy, int player);

// handle players
int player_1(char **map_self, char **map_enemy);
int player_2(char **map_self, char **map_enemy, char const *pid);

// utiles
pos_t get_line(void);
void print_map(char **map, char **map_enemy);
int check_win_lose(char **map_self, char **map_enemy);
#endif /* !MY_NAVY_H_ */
