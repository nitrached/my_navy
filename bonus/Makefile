##
## EPITECH PROJECT, 2023
## Untitled (Workspace)
## File description:
## Makefile
##

NAME		= my_navy

SRCS		= src/main.c \
			  src/innit_free/free_all.c \
			  src/innit_free/innit.c \
			  src/get_info/get_info.c \
			  src/get_info/fill_struct.c \
			  src/get_info/get_map.c \
			  src/players/player_1.c \
			  src/get_line/get_line.c \
			  src/signal_handler/send_signal.c \
			  src/players/play.c \
			  src/players/miss_hit.c \
			  src/players/handle_coords.c \
			  src/players/player_2.c \
			  src/players/game.c \
			  src/players/win_lose.c \
			  src/signal_handler/signal_handler.c \
			  src/map/print_map.c \
			  src/map/check_win_lose.c

OBJS     = $(SRCS:.c=.o)

CFLAGS   = -Wall -Wextra -I include -I lib/include

	GREEN=\033[1;32m
	YELLOW=\033[1;93m
	GREY=\033[2;49m
	ITALIC=\033[3m
	NC=\033[0m

all: $(NAME)

$(NAME): build_lib $(OBJS)
	 	@ gcc -o $(NAME) $(OBJS) -L./lib -lmy

build_lib:
	make -C ./lib

clean:
	make fclean -C ./lib
	$(RM) $(OBJS) $(NAME)
	find . -name "#*#" -delete -o -name "*~" -delete
	$(RM) coding-style-reports.log
	$(RM) vgcore*
	clear

fclean: clean
	$(RM) a.out
	$(RM) lib/libmy.a
	clear

re: fclean all

debug: fclean
debug: CFLAGS += -g
debug: all

.c.o:
	@ $(CC) -o $(subst .c,.o,$<) -c $< $(CFLAGS) \
		&& echo -e "[ ${GREEN}OK${NC} ] ${GREY}$<${NC}" \
		|| echo -e "[ ${YELLOW}KO${NC} ] ${ITALIC}$<${NC}"

.PHONY: re fclean clean all .c.o
