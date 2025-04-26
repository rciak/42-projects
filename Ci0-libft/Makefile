# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Rene Ciak <rciakAT42Vienna@web.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 11:30:15 by Rene Ciak         #+#    #+#              #
#    Updated: 2025/04/26 17:46:59 by Rene Ciak        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
INC_DIR := .
OBJ_DIR := ./obj

CC := cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)
RM := rm -f
RMDIR := rmdir

OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))
SRCS := \
./ft_isalnum.c \

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o:%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(OBJS)
	-$(RM) $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

.PHONY: bonus
bonus:

.PHONY: bonus
bonus_re: fclean bonus