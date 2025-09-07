# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/01 20:46:12 by reciak            #+#    #+#              #
#    Updated: 2025/09/07 13:34:18 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := fractol
LIBFT_NAME  := libft.a
LIBFT_DIR   := libft
LIBFT       := $(LIBFT_DIR)/$(LIBFT_NAME)
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
ifeq ($(GPROF), 1)
  CFLAGS += -pg
  LDFLAGS += -pg
endif
ifeq ($(OPTI_ON), 1)
  CFLAGS += -O3
  NAME := $(NAME)_O3
endif

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
#############################################
INCS := \
libft/libft.h \
inc/fractol_bonus.h

SRCS := \
src/error_bonus.c \
src/init_image_struct_bonus.c \
src/init_non_mlx_vars/init_math_bonus.c \
src/init_non_mlx_vars/init_non_mlx_vars_bonus.c \
src/init_non_mlx_vars/init_palette_bonus.c \
src/init_non_mlx_vars/reset_square_bonus.c \
src/main_bonus.c \
src/math/calc_iterations_bonus.c \
src/math/coord_transf_bonus.c \
src/math/escape_criteria/criteria_circle_julia_bonus.c \
src/math/escape_criteria/criteria_circle_mbrot_bonus.c \
src/math/escape_criteria/criteria_square_julia_bonus.c \
src/math/escape_criteria/criteria_square_mbrot_bonus.c \
src/math/fractal_genes/z_pow_2_plus_w_bonus.c \
src/math/fractal_genes/z_pow_3_plus_w_bonus.c \
src/math/fractal_genes/z_pow_4_plus_w_bonus.c \
src/math/fractal_genes/z_pow_5_plus_w_bonus.c \
src/math/fractal_genes/z_pow_6_plus_w_bonus.c \
src/math/fractal_genes/z_pow_7_plus_w_bonus.c \
src/math/fractal_genes/z_pow_8_plus_w_bonus.c \
src/math/fractal_genes/z_pow_9_plus_w_bonus.c \
src/math/square_in_allowed_region_bonus.c \
src/mlx_callbacks/events_julia_bonus.c \
src/mlx_callbacks/events_mbrot_bonus.c \
src/mlx_callbacks/img_iter_to_color_bonus.c \
src/mlx_callbacks/induced_changes_of_vars/change_id_bonus.c \
src/mlx_callbacks/induced_changes_of_vars/change_julia_param_bonus.c \
src/mlx_callbacks/induced_changes_of_vars/change_max_iter_bonus.c \
src/mlx_callbacks/induced_changes_of_vars/shift_bonus.c \
src/mlx_callbacks/induced_changes_of_vars/toggle_escape_criteria_bonus.c \
src/mlx_callbacks/induced_changes_of_vars/zoom_bonus.c \
src/mlx_callbacks/waiting_for_godot_bonus.c \
src/printing/print_error_bonus.c \
src/printing/print_info_bonus.c \
src/printing/print_usage_bonus.c \
src/printing/put_complex_number_bonus.c \
src/printing/put_double_bonus.c \
src/printing/welcome_traveler_bonus.c
#############################################

.PHONY: all
all: $(NAME)
$(NAME): $(OBJS) $(LIBFT)
	@make --quiet libft_archive_provided
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(INCS) | libftall
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
re: fclean libftfclean all

.PHONY: bonus
bonus: all

################################################################################
#  libft  related rules                                                        #
################################################################################

.PHONY: libftall
libftall: $(LIBFT)

$(LIBFT): libft_greeting
	make -C  $(LIBFT_DIR) all
	@echo

.PHONY: libftbonus
libftbonus: libft_greeting
	make -C $(LIBFT_DIR) bonus
	@echo

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

