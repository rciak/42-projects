# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/01 20:46:12 by reciak            #+#    #+#              #
#    Updated: 2025/10/03 16:11:38 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME          := pipex
LIBFT_NAME    := libft.a
LIBFT_DIR     := libft
LIBFT         := $(LIBFT_DIR)/$(LIBFT_NAME)
INC_DIRS      := inc $(LIBFT_DIR)/inc
SRC_DIR       := src
OBJ_DIR       := obj
OBJ_DIR_BONUS := obj

RM       := rm -f
RM_FR    := rm -fr
CC       := cc
CFLAGS    = -Wall -Wextra -Werror $(addprefix -I,$(INC_DIRS))
LDFLAGS  = -L $(LIBFT_DIR)
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
# update via makefile rule (small "m" !)
#   make update_INCS__SRCS__SRCS_BONUS
#############################################
include makefile_dir/def_headers.mk
include makefile_dir/def_sources.mk
#############################################

.PHONY: all
all: print_project $(NAME)
$(NAME): $(OBJS) $(LIBFT)
	@make --quiet libft_archive_provided
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(INCS) | entry_message_compile
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean: print_project
	@echo 'CLEANING via rule  clean'
	@echo '  1. Removing timestamp file (created for bonus part), if any.'
	@$(RM_FR) $(TIMESTAMPFILE_BONUS)
	@echo '  2. Removing object files, if any.'
	@$(RM_FR) $(OBJS) $(OBJS_BONUS)
	@if [ ! -d $(OBJ_DIR) ]; then \
		: ; \
	elif [ $(OBJ_DIR) = '.' ]; then \
		echo '     Well if the object files would be in their own separte'; \
		echo '     directory that directory shall be removed, but here:'; \
		echo '     Removing the directory . will not even been tried. ...'; \
	else \
		$(RM_FR) $(OBJ_DIR); \
	fi
	@if [ ! -d $(OBJ_DIR_BONUS) ] && [ "$(OBJ_DIR)" = "$(OBJ_DIR_BONUS)" ]; \
	then \
		: ; \
	elif [ $(OBJ_DIR_BONUS) = '.' ]; then \
		echo '     Well if the object files would be in their own separte'; \
		echo '     directory that directory shall be removed, but here:'; \
		echo '     Removing the directory . will not even been tried. ...'; \
	else \
		$(RM_FR) $(OBJ_DIR_BONUS); \
	fi

.PHONY: fclean
fclean: clean
	@echo 'CLEANING additional via rule  fclean'
	@echo 'Removing $(NAME), if any.' 
	@$(RM_FR) $(NAME)
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

$(LIBFT):
	@make -C  $(LIBFT_DIR) all
	@echo
	@$(MAKE) print_project

.PHONY: libftbonus
libftbonus:
	@make -C $(LIBFT_DIR) bonus
	@echo

.PHONY: libftclean
libftclean:
	@make -C $(LIBFT_DIR) clean

.PHONY: libftfclean
libftfclean:
	@make -C $(LIBFT_DIR) fclean

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

################################################################################
# PRINTING RULES                                                               #
################################################################################

PHONY: print_project
print_project:
	@echo '*******************************************************************'
	@echo '*                              PIPEX                              *'
	@echo '*******************************************************************'

.PHONY: entry_message_compile
entry_message_compile:
	@echo 'COMPILING (if need) ...'
