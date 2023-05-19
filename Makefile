# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 13:53:36 by evocatur          #+#    #+#              #
#    Updated: 2023/05/19 14:20:04 by evocatur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

SRC = $(UTILITIES_SRC) $(MAP_SRC) $(GAME_SRC)  $(GNL_SRC) $(LIBFT_SRC) $(MAIN_SRC)

MAIN_SRC = *.c

MAP_SRC = map_script/*.c

GAME_SRC = game_script/*.c

GNL_SRC = gnl/*.c

LIBFT_SRC = ft_libft/*.c

UTILITIES_SRC = utilities/error.c


OBJ = *.o

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
LINKS += -Lmlx_linux -lmlx_Linux
endif

ifeq ($(UNAME_S),Darwin)
LINKS += -lmlx -framework OpenGL -framework AppKit
endif

FLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJ) $(LINKS) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@rm -rf $(OBJ)
	
$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAAGS) -c $(SRC)

exe: all
	@echo "     - Executing $(NAME)... \n"
	@./$(NAME)
	@echo "\n     - Done -"

play0: all
	@./$(NAME) Map/map_0.ber

leaks: all
	@leaks --atExit -- ./$(NAME) map/map_0.ber

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)

re: fclean all