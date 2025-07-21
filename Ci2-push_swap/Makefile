# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/01 20:46:12 by reciak            #+#    #+#              #
#    Updated: 2025/07/21 17:13:11 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := push_swap
LIBFT_NAME  := libft.a
LIBFT_DIR   := libft
INC_DIR     := inc
SRC_DIR     := src
OBJ_DIR     := obj

RM       := rm -f
RM_FR    := rm -fr
CC       := cc
CFLAGS    = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)
LDFLAGS  = -L $(LIBFT_DIR) -lft -lmlx -lXext -lX11 -lm
ifeq ($(DEBUG_LAUB_SAN), 1)
  CFLAGS  += -g3 -fsanitize=address,undefined,leak
  LDFLAGS += -g3 -fsanitize=address,undefined,leak
endif
ifeq ($(DEBUG_M_SAN), 1)
  CFLAGS  += -g3 -fsanitize=memory -fsanitize-memory-track-origins=2
  LDFLAGS += -g3 -fsanitize=memory -fsanitize-memory-track-origins=2
endif
ifeq ($(DEBUG_VALGRIND), 1)
  CFLAGS  += -g3
  LDFLAGS += -g3
endif

OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))
#############################################
INCS := \
libft/libft.h \
inc/push_swap.h

SRCS := \
src/main.c
#############################################

.PHONY: all
all: $(NAME)
$(NAME): $(OBJS) | libftall
	@make --quiet libft_archive_provided
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

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
libftall: libft_greeting
	make -C  $(LIBFT_DIR) all

.PHONY: libftbonus
libftbonus: libft_greeting
	make -C $(LIBFT_DIR) bonus

.PHONY: libftclean
libftclean: libft_greeting
	make -C $(LIBFT_DIR) clean

.PHONY: libftfclean
libftfclean: libft_greeting
	make -C $(LIBFT_DIR) fclean

.PHONY: libft_greeting
libft_greeting:
	@echo '########################  LIBFT  ###  LIBFT  ###  LIBFT  '\
	      '########################'


################################################################################
#  tools and helpers                                                           #
################################################################################

#Check if libft.a is provided at the expected location
.PHONY: libft_archive_provided
libft_archive_provided:
	@echo "Checking for $(LIBFT_DIR)/$(LIBFT_NAME) ..."
	@if [ ! -e $(LIBFT_DIR)/$(LIBFT_NAME) ]; \
		then echo "--> Not found!"; exit 1;  \
	fi;

