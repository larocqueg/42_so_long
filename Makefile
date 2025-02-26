# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 15:21:10 by gde-la-r          #+#    #+#              #
#    Updated: 2025/02/14 15:21:12 by gde-la-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output name
NAME = so_long

# Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Paths
SRC_DIR = ./src
INCLUDES = ./includes
LIBFT_DIR = ./libft

# Sources
SRC = $(SRC_DIR)/main.c \
	  $(SRC_DIR)/utils.c \
	  $(SRC_DIR)/validation.c 

# Objects
OBJS = $(SRC:.c=.o)
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -I $(LIBFT_DIR) -c $< -o $@

clean: 
	rm -rf $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean
	make all
