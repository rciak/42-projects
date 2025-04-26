# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Rene Ciak <rciakAT42Vienna@web.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 11:30:15 by Rene Ciak         #+#    #+#              #
#    Updated: 2025/04/26 22:46:26 by Rene Ciak        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
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

TIMESTAMPFILE_BONUS = .timestamp_file_bonus_avoiding_unnecessary_relinking
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
	$(RM) $(TIMESTAMPFILE_BONUS)
	-$(RMDIR) $(OBJ_DIR)
	-$(RMDIR) $(OBJ_DIR_BONUS)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

.PHONY: bonus
bonus: $(TIMESTAMPFILE_BONUS)

$(TIMESTAMPFILE_BONUS): $(OBJS) $(OBJS_BONUS)
	touch	$(TIMESTAMPFILE_BONUS)
	ar -crs	$(NAME) $(OBJS) $(OBJS_BONUS)

$(OBJ_DIR_BONUS)/%.o:%.c $(INCS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: rebonus
rebonus: fclean bonus
