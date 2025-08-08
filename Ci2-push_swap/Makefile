# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/01 20:46:12 by reciak            #+#    #+#              #
#    Updated: 2025/08/08 16:46:28 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

export NAME := push_swap
LIBFT_NAME  := libft.a
LIBFT_DIR   := libft
INC_DIR     := inc
SRC_DIR     := src
OBJ_DIR     := obj

RM       := rm -f
RM_FR    := rm -fr
CC       := cc
CFLAGS    = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)
LDFLAGS  = -L $(LIBFT_DIR) -lft
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
export INCS := \
libft/libft.h \
inc/push_swap.h

export SRCS := \
src/big_size_algo.c \
src/error.c \
src/main.c \
src/small_size_algo.c \
src/group_tools/be_group.c \
src/group_tools/group_already_sorted.c \
src/group_tools/group_memb_last.c \
src/group_tools/group_size.c \
src/group_tools/is_cyclic.c \
src/group_tools/is_on_a.c \
src/group_tools/max_non_green_group.c \
src/group_tools/truly_max_group.c \
src/group_tools/update_group.c \
src/join_green_directsort/join_green_directsort.c \
src/join_green_directsort/join_green_size_1.c \
src/join_green_directsort/join_green_size_2.c \
src/join_green_directsort/join_green_size_3.c \
src/operations_basic/pa.c \
src/operations_basic/pb.c \
src/operations_basic/ra.c \
src/operations_basic/rb.c \
src/operations_basic/rra.c \
src/operations_basic/rrb.c \
src/operations_basic/sa.c \
src/operations_basic/sb.c \
src/operations_basic/ss.c \
src/operations_basic/swap.c \
src/operations_generalized/p_it.c \
src/operations_generalized/rev_r_it.c \
src/operations_generalized/r_it.c \
src/trivide/trivide.c \
src/trivide/trivide_end_group.c \
src/trivide/trivide_top_group.c
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

