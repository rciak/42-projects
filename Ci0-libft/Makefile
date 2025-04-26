# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Rene Ciak <rciakAT42Vienna@web.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 11:30:15 by Rene Ciak         #+#    #+#              #
#    Updated: 2025/04/26 20:42:56 by Rene Ciak        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Abvoid any implicit rules
.SUFFIXES:

NAME := libft.a
NAME_BONUS = $(OBJ_DIR)/libft_bonus_extra_file_to_avoid_unnecessary_relinking.a
INC_DIR := .
OBJ_DIR := ./obj
OBJ_DIR_BONUS := ./obj_bonus

CC := cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)
RM := rm -f
RMDIR := rmdir

# Dependencies can be handled better using DEP=.. stuff, cf.
# https://stackoverflow.com/questions/2394609/makefile-header-dependencies
# but that is currently beyond my understanding and for not too big problems
# it should be ok if everything is recompiled when the header changes.
INCS := ./libft.h

OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))
SRCS := \
./ft_isalnum.c

OBJS_BONUS = $(patsubst %.c,$(OBJ_DIR_BONUS)/%.o,$(SRCS_BONUS))
SRCS_BONUS := \
./ft_lstnew.c

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

$(OBJ_DIR)/%.o:%.c $(INCS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(RM) $(NAME_BONUS)
	-$(RMDIR) $(OBJ_DIR)
	-$(RMDIR) $(OBJ_DIR_BONUS)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

.PHONY: bonus
bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS) $(OBJS_BONUS)
	ar -crs	$(NAME_BONUS) $(OBJS) $(OBJS_BONUS)
	cp $(NAME_BONUS) $(NAME)

$(OBJ_DIR_BONUS)/%.o:%.c $(INCS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: rebonus
rebonus: fclean bonus
