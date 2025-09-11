# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 16:37:47 by reciak            #+#    #+#              #
#    Updated: 2025/09/11 15:27:47 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
INC_DIR := inc 
OBJ_DIR := .
OBJ_DIR_BONUS := .

CC := cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)
RM := rm -f
RMDIR := rmdir

ifeq ($(DEBUG_LAUB_SAN), 1)
  CFLAGS  += -g3 -fsanitize=address,undefined,leak
endif
ifeq ($(DEBUG_M_SAN), 1)
  CFLAGS  += -g3 -fsanitize=memory -fsanitize-memory-track-origins=2
endif
ifeq ($(DEBUG_VALGRIND), 1)
  CFLAGS  += -g3
endif
ifeq ($(GPROF), 1)
  CFLAGS += -pg
endif


# Dependencies can be handled better using DEP=.. stuff, cf.
# https://stackoverflow.com/questions/2394609/makefile-header-dependencies
# but that is currently beyond my understanding and for not too big projects
# it should be ok if everything is recompiled when the header changes.
INCS := \
./inc/ft_printf.h \
./inc/get_next_line.h \
./inc/libft.h

SRCS := \
./atof_strict.c \
./atoi_strict.c \
./atoll_strict.c \
./dl_lst_add_after.c \
./dl_lst_add_before.c \
./dl_lst_circularize.c \
./dl_lst_clear.c \
./dl_lst_linearize.c \
./dl_lst_new_nd.c \
./dl_lst_size.c \
./dl_lst_type.c \
./free_array.c \
./ft_atoi.c \
./ft_bzero.c \
./ft_calloc.c \
./ft_isalnum.c \
./ft_isalpha.c \
./ft_isascii.c \
./ft_isdigit.c \
./ft_isprint.c \
./ft_itoa.c \
./ft_memchr.c \
./ft_memcmp.c \
./ft_memcpy.c \
./ft_memmove.c \
./ft_memset.c \
./ft_putchar_fd.c \
./ft_putendl_fd.c \
./ft_putllnbr_fd.c \
./ft_putnbr_fd.c \
./ft_putstr_fd.c \
./ft_split.c \
./ft_strchr.c \
./ft_strcmp.c \
./ft_strdup.c \
./ft_striteri.c \
./ft_strjoin.c \
./ft_strlcat.c \
./ft_strlcpy.c \
./ft_strlen.c \
./ft_strmapi.c \
./ft_strncmp.c \
./ft_strnstr.c \
./ft_strrchr.c \
./ft_strtrim.c \
./ft_substr.c \
./ft_tolower.c \
./ft_toupper.c \
./ft_x_math01.c \
./ft_x_memtools1.c \
./ft_x_strtools1.c \
./ft_xx_out1.c \
./ft_xx_out2.c \
./is_listed.c \
./side_products/ft_x_strtools2.c \
./src/ft_printf/src/ft_printf.c \
./src/gnl/get_next_line.c \
./src/gnl/get_next_line_utils.c

SRCS_BONUS := \
./ft_lstadd_back_bonus.c \
./ft_lstadd_front_bonus.c \
./ft_lstclear_bonus.c \
./ft_lstdelone_bonus.c \
./ft_lstiter_bonus.c \
./ft_lstlast_bonus.c \
./ft_lstmap_bonus.c \
./ft_lstnew_bonus.c \
./ft_lstsize_bonus.c

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
	@echo 'CLEANING via rule  clean'
	@echo '1. Removing object files, if any.'
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@echo '2. Removing timestamp file (created for bonus part), if any.'
	@$(RM) $(TIMESTAMPFILE_BONUS)
	@echo '3.a) Removing directory for mandatory object files, if any.'
	@if [ ! -d $(OBJ_DIR) ]; then \
		echo 'No directory $(OBJ_DIR) for mandatory object files.'; \
	elif [ $(OBJ_DIR) = '.' ]; then \
		echo '       Well if the object files would be in their own separte'; \
		echo '       directory that directory shall be removed, but here:'; \
		echo '       Removing the directory . will not even been tried. ...'; \
	else \
		-$(RMDIR) $(OBJ_DIR); \
	fi
	@echo '3.b) Removing directory for bonus object files, if any.'
	@if [ ! -d $(OBJ_DIR_BONUS) ]; then \
		echo 'No directory $(OBJ_DIR_BONUS) for bonus object files.'; \
	elif [ $(OBJ_DIR_BONUS) = '.' ]; then \
		echo '       Well if the object files would be in their own separte'; \
		echo '       directory that directory shall be removed, but here:'; \
		echo '       Removing the directory . will not even been tried. ...'; \
	else \
		-$(RMDIR) $(OBJ_DIR_BONUS); \
	fi
	@echo '- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -'

.PHONY: fclean
fclean: clean
	@echo 'CLEANING additional via rule  fclean:'
	@echo 'Removing $(NAME), if any.' 
	@$(RM) $(NAME)
	@echo '--------------------------------------------------------------------'

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
