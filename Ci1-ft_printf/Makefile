# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/01 20:46:12 by reciak            #+#    #+#              #
#    Updated: 2025/06/17 20:02:08 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME       := libftprintf.a
LIBFT_NAME := libft.a
LIBFT_DIR  := libft
INC_DIR    := inc
SRC_DIR    := src
OBJ_DIR    := obj

RM       := rm -f
RM_FR    := rm -fr
CC       := cc
CFLAGS    = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)
ifeq ($(DEBUG), 1)
  CFLAGS += -g3 -fsanitize=address,undefined,leak
endif

OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))
#############################################
INCS := \
libft/libft.h \
inc/ft_printf.h

SRCS := \
src/ft_printf.c
#############################################

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) | libftall
	cp $(LIBFT_DIR)/$(LIBFT_NAME) $(NAME)
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
	@$(RM_FR) $(OBJ_DIR)
	@echo '3.b) Removing directory for bonus object files, if any.'
	@$(RM_FR) $(OBJ_DIR_BONUS);
	@echo '- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -'

.PHONY: fclean
fclean: clean
	@echo 'CLEANING additional via rule  fclean:'
	@echo 'Removing $(NAME), if any.' 
	@$(RM) $(NAME)
	@echo '--------------------------------------------------------------------'

.PHONY: re
re: fclean all

################################################################################
#  libft  related rules                                                        #
################################################################################

.PHONY: libftall
libftall:
	make -C $(LIBFT_DIR) all

.PHONY: libftbonus
libftbonus:
	make -C $(LIBFT_DIR) bonus

.PHONY: libftclean
libftclean:
	make -C $(LIBFT_DIR) clean

.PHONY: libftfclean
libftfclean:
	make -C $(LIBFT_DIR) fclean