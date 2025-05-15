# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 16:37:47 by reciak            #+#    #+#              #
#    Updated: 2025/05/15 10:00:52 by reciak           ###   ########.fr        #
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
INCS := \
./libft.h

SRCS := \
./ft_strrchr.c \
./ft_substr.c \
./ft_bzero.c \
./ft_tolower.c \
./ft_strjoin.c \
./ft_strncmp.c \
./ft_putendl_fd.c \
./ft_strlcpy.c \
./ft_toupper.c \
./ft_memmove.c \
./ft_memcpy.c \
./ft_putstr_fd.c \
./ft_strlcat.c \
./ft_calloc.c \
./ft_isalnum.c \
./ft_strchr.c \
./ft_isdigit.c \
./ft_memchr.c \
./ft_isascii.c \
./ft_strlen.c \
./ft_isalpha.c \
./ft_atoi.c \
./ft_strdup.c \
./ft_x_math01.c \
./ft_memset.c \
./ft_strtrim.c \
./ft_memcmp.c \
./ft_isprint.c \
./ft_putchar_fd.c \
./ft_strnstr.c \
./ft_x_strtools1.c \
./ft_x_memtools1.c

SRCS_BONUS := \
./ft_lstnew.c

OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))
TIMESTAMPFILE_BONUS = .timestamp_file_bonus_avoiding_unnecessary_relinking
OBJS_BONUS = $(patsubst %.c,$(OBJ_DIR_BONUS)/%.o,$(SRCS_BONUS))

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
