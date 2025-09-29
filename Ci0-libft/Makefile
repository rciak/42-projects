# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 16:37:47 by reciak            #+#    #+#              #
#    Updated: 2025/09/29 11:18:15 by reciak           ###   ########.fr        #
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
./src/00_libft_piscine/ft_strcmp.c \
./src/01_libft_libc/ft_atoi.c \
./src/01_libft_libc/ft_bzero.c \
./src/01_libft_libc/ft_calloc.c \
./src/01_libft_libc/ft_isalnum.c \
./src/01_libft_libc/ft_isalpha.c \
./src/01_libft_libc/ft_isascii.c \
./src/01_libft_libc/ft_isdigit.c \
./src/01_libft_libc/ft_isprint.c \
./src/01_libft_libc/ft_memchr.c \
./src/01_libft_libc/ft_memcmp.c \
./src/01_libft_libc/ft_memcpy.c \
./src/01_libft_libc/ft_memmove.c \
./src/01_libft_libc/ft_memset.c \
./src/01_libft_libc/ft_strchr.c \
./src/01_libft_libc/ft_strdup.c \
./src/01_libft_libc/ft_strlcat.c \
./src/01_libft_libc/ft_strlcpy.c \
./src/01_libft_libc/ft_strlen.c \
./src/01_libft_libc/ft_strncmp.c \
./src/01_libft_libc/ft_strnstr.c \
./src/01_libft_libc/ft_strrchr.c \
./src/01_libft_libc/ft_tolower.c \
./src/01_libft_libc/ft_toupper.c \
./src/02_libft_others/ft_itoa.c \
./src/02_libft_others/ft_putchar_fd.c \
./src/02_libft_others/ft_putendl_fd.c \
./src/02_libft_others/ft_putnbr_fd.c \
./src/02_libft_others/ft_putstr_fd.c \
./src/02_libft_others/ft_split.c \
./src/02_libft_others/ft_striteri.c \
./src/02_libft_others/ft_strjoin.c \
./src/02_libft_others/ft_strmapi.c \
./src/02_libft_others/ft_strtrim.c \
./src/02_libft_others/ft_substr.c \
./src/04_ft_printf/src/ft_printf.c \
./src/05_get_next_line/get_next_line.c \
./src/05_get_next_line/get_next_line_utils.c \
./src/06_doubly_linked_list/dl_lst_add_after.c \
./src/06_doubly_linked_list/dl_lst_add_before.c \
./src/06_doubly_linked_list/dl_lst_circularize.c \
./src/06_doubly_linked_list/dl_lst_clear.c \
./src/06_doubly_linked_list/dl_lst_linearize.c \
./src/06_doubly_linked_list/dl_lst_new_nd.c \
./src/06_doubly_linked_list/dl_lst_size.c \
./src/06_doubly_linked_list/dl_lst_type.c \
./src/07_conversions/atof_strict.c \
./src/07_conversions/atoi_proper.c \
./src/07_conversions/atoi_strict.c \
./src/07_conversions/atoll_strict.c \
./src/08xx_output/ft_putllnbr_fd.c \
./src/08xx_output/ft_xx_astatic_helpers/out_uintptr.c \
./src/08xx_output/ft_xx_astatic_helpers/out_uintptr_fd.c \
./src/08xx_output/ft_xx_behind_wrappers/out_nbr_fd.c \
./src/08xx_output/ft_xx_behind_wrappers/out_str_fd.c \
./src/08xx_output/ft_xx_behind_wrappers/out_unbr_fd.c \
./src/08xx_output/ft_xx_behind_wrappers/out_vptr_fd.c \
./src/08xx_output/ft_xx_wrappers_for_ft_printf/out_nbr.c \
./src/08xx_output/ft_xx_wrappers_for_ft_printf/out_str.c \
./src/08xx_output/ft_xx_wrappers_for_ft_printf/out_unbr.c \
./src/08xx_output/ft_xx_wrappers_for_ft_printf/out_vptr.c \
./src/09x_memtools/ft_x/calloc_uninit.c \
./src/09x_memtools/ft_x/si_is_overflow.c \
./src/10x_string_tools/count_words.c \
./src/10x_string_tools/free_array.c \
./src/10x_string_tools/ft_x/is_in.c \
./src/10x_string_tools/ft_x/si_substr.c \
./src/10x_string_tools/is_listed.c \
./src/10x_string_tools/skip.c \
./src/10x_string_tools/split_deli.c \
./src/10x_string_tools/strlen_deli.c \
./src/11x_math/ft_x/abs.c \
./src/11x_math/ft_x/si_min.c \
./src/11x_math/si_max.c

SRCS_BONUS := \
./src/03_libft_singly_linked_list/ft_lstadd_back_bonus.c \
./src/03_libft_singly_linked_list/ft_lstadd_front_bonus.c \
./src/03_libft_singly_linked_list/ft_lstclear_bonus.c \
./src/03_libft_singly_linked_list/ft_lstdelone_bonus.c \
./src/03_libft_singly_linked_list/ft_lstiter_bonus.c \
./src/03_libft_singly_linked_list/ft_lstlast_bonus.c \
./src/03_libft_singly_linked_list/ft_lstmap_bonus.c \
./src/03_libft_singly_linked_list/ft_lstnew_bonus.c \
./src/03_libft_singly_linked_list/ft_lstsize_bonus.c

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
