# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 16:11:19 by ttroll            #+#    #+#              #
#    Updated: 2019/04/12 17:30:50 by ttroll           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PSWP 	= push_swap
CHCK	= checker

SRC_DIR = ./src
OBJ_DIR = ./obj

PS_DIR	= $(SRC_DIR)/push_swap_dir
CH_DIR	= $(SRC_DIR)/checker
SH_DIR  = $(SRC_DIR)/shared

PS_O_DIR = $(OBJ_DIR)/push_swap_dir
CH_O_DIR = $(OBJ_DIR)/checker
SH_O_DIR = $(OBJ_DIR)/shared

LIB_DIR = ./libft
LIB 	= $(LIB_DIR)libft.a

PS_O 	 = $(addprefix $(PS_O_DIR)/, $(PS_FILES:%.c=%.o))
CH_O	 = $(addprefix $(CH_O_DIR)/, $(CH_FILES:%.c=%.o))
SH_O	 = $(addprefix $(SH_O_DIR)/, $(SH_FILES:%.c=%.o))

PS_FILES = rotation_helpers.c stack_sort.c sort_helpers.c  push_swap_main.c
CH_FILES = execute_commands.c graphics.c graphics_helpers.c console_visualizer.c checker_main.c
SH_FILES = operations.c more_operations.c stack_funcs.c validation.c


CC		 = gcc
SDL_CFLAGS = $(shell sdl2-config --cflags)
SDL_LDFLAGS = $(shell sdl2-config --libs)
FLAGS	 = -Wall -Wextra -Werror

INC	= -I $(LIB_DIR)/includes -I ./includes
LIB_LNK = -L $(LIB_DIR) -lft

all: sort check

sort: $(LIB) $(PSWP)

check: $(LIB) $(CHCK)

$(LIB):
	@make -C $(LIB_DIR)

$(SH_O_DIR):
	@mkdir -p $@

$(CH_O_DIR):
	@mkdir -p $@

$(PS_O_DIR):
	@mkdir -p $@

$(PSWP): $(SH_O) $(PS_O)
	$(CC) $(FLAGS) $(INC) $(SH_O) $(PS_O) -o $(PSWP) $(LIB_LNK)

$(CHCK): $(SH_O) $(CH_O)
	$(CC) $(FLAGS) $(SDL_CFLAGS) $(INC) $(SH_O) $(CH_O) -o $(CHCK) $(LIB_LNK) $(SDL_LDFLAGS)

$(addprefix $(PS_O_DIR)/, %.o): $(addprefix $(PS_DIR)/, %.c) | $(PS_O_DIR)
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

$(addprefix $(CH_O_DIR)/, %.o): $(addprefix $(CH_DIR)/, %.c) | $(CH_O_DIR)
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

$(addprefix $(SH_O_DIR)/, %.o): $(addprefix $(SH_DIR)/, %.c) | $(SH_O_DIR)
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIB_DIR)

fclean: clean
	make fclean -C $(LIB_DIR)
	rm -f $(CHCK) $(PSWP)

re: fclean all
