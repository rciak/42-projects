# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/22 21:15:03 by reciak            #+#    #+#              #
#    Updated: 2025/06/17 19:54:02 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# DO NOT CHANGE
PROJECT_TITLE    := ft_printf
UNIT_TESTS_FILE  := ft_printf-tests.c
SRC_MANUAL_TEST := manual_test_ft_printf.c

# ADOPT:
#   BASE_DIR:      Location of Makefile (the one that builts the project target)
#   INC_DIRS:      Locations where header files are, e.g.
#                     libftprintf.h   and  libft.h  
#   LIB_FILE_NAME:    libftprintf.a  (probably no need to change)
BASE_DIR        := ../../
INC_DIRS        := inc/  libft/
LIB_FILE_NAME   := libftprintf.a

INC_DIRS      := $(addprefix -I$(BASE_DIR),$(INC_DIRS))
OUT_UNIT_TEST := $(basename $(UNIT_TESTS_FILE))
LIB_FILE      := $(BASE_DIR)$(LIB_FILE_NAME)

CC     := cc
CFLAGS := -Wall -Wextra -Werror
CFLAGS += -Wno-format-security#To prevent warning issues (printf -security)
CFLAGS += $(INC_DIRS)
ifeq ($(DEBUG), 1)
	CFLAGS += -g3 -fsanitize=address,undefined,leak
endif
LFLAGS = -lcriterion $(LIB_FILE)
RM    := rm -f

.PHONY: unit-tests
unit-tests:
	@echo
	@echo '************ This is 42-eva-lua for $(PROJECT_TITLE) ************'
	@echo
	@echo '1. Calling make in $(BASE_DIR) which should provide $(LIB_FILE_NAME)'
	@echo '-------'
	@make -C $(BASE_DIR)
	@echo '-------'
	@echo 'Looking in $(BASE_DIR) for $(LIB_FILE_NAME) ...'
	@if [ ! -e $(LIB_FILE) ]; then \
	  echo '   ... Not found. Stop.' && exit 1; \
	else \
	  echo '   ... Found! Continuing.'; \
	fi
	@echo '2. Compiling tests'
	@echo '   -->  $(OUT_UNIT_TEST)'
	@$(CC) $(CFLAGS) $(UNIT_TESTS_FILE) $(LFLAGS) -o $(OUT_UNIT_TEST)
	@echo '3. Executing tests'
	@echo '      ./$(OUT_UNIT_TEST)'
	@echo
	@./$(OUT_UNIT_TEST)

OUT_MAN_TEST = $(patsubst %.c,%,$(SRC_MANUAL_TEST))
.PHONY: manual-test
manual-test:
	$(CC) $(CFLAGS) $(SRC_MANUAL_TEST) $(LIB_FILE) -o $(OUT_MAN_TEST)
	@echo 'Sample use of manual test:'
	@echo "  ./$(OUT_MAN_TEST) 'dog' -23 11"

.PHONY: fclean
fclean:
	$(RM) $(OUT_UNIT_TEST)
	$(RM) $(OUT_MAN_TEST)

.PHONY: re
re: fclean unit-tests

