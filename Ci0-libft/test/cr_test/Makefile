# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/22 21:15:03 by reciak            #+#    #+#              #
#    Updated: 2025/10/01 21:04:57 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# DO NOT CHANGE
PROJECT_TITLE    := ft_printf
UNIT_TESTS_FILE  := ft_printf-tests.c

# ADOPT:
#   BASE_DIR:      Location of Makefile (the one that builts the project target)
#   INC_DIRS:      Locations where header files are, e.g.
#                     libftprintf.h   and  libft.h  
#   LIB_FILE_NAME:    libftprintf.a  (probably no need to change)
BASE_DIR        := ../../
INC_DIRS        := inc
LIB_FILE_NAME   := libftprintf.a

OUT_UNIT_TEST := $(basename $(UNIT_TESTS_FILE))
LIB_FILE      := $(BASE_DIR)$(LIB_FILE_NAME)

CC     := cc
CFLAGS := -Wall -Wextra -Werror
CFLAGS += -Wno-format-security#To prevent warning issues (printf -security)
CFLAGS += $(addprefix -I$(BASE_DIR),$(INC_DIRS))
ifeq ($(DEBUG_LAUB_SAN), 1)
  CFLAGS  += -g3 -fsanitize=address,undefined,leak
endif
ifeq ($(DEBUG_M_SAN), 1)
  CFLAGS  += -g3 -fsanitize=memory -fsanitize-memory-track-origins=2
endif
ifeq ($(DEBUG_VALGRIND), 1)
  CFLAGS  += -g3
endif
LFLAGS = -lcriterion $(LIB_FILE)
RM    := rm -f

ifneq ($(VERBOSITY), 1)
  INFLUENCE_STDOUT = > /dev/null
endif



.PHONY: unit-tests
unit-tests:
	@echo
	@echo '************************** Criterion Test **************************'
	@echo '* $(PROJECT_TITLE)'
	@echo '********************************************************************'
	@echo
	@echo '1. Calling make in $(BASE_DIR) which should provide $(LIB_FILE_NAME)'
	@make -C $(BASE_DIR)
	@echo 'Looking in $(BASE_DIR) for $(LIB_FILE_NAME) ...'
	@if [ ! -e $(LIB_FILE) ]; then \
	  echo '   -->  Not found. Stop.' && exit 1; \
	else \
	  echo '   -->  Found! Continuing.'; \
	fi
	@echo '2. Compiling tests'
	@echo '   -->  $(OUT_UNIT_TEST)'
	@$(CC) $(CFLAGS) $(UNIT_TESTS_FILE) $(LFLAGS) -o $(OUT_UNIT_TEST)
	@echo '3. Executing tests'
	@echo '   -->  ./$(OUT_UNIT_TEST)'
	@echo
	@./$(OUT_UNIT_TEST) $(INFLUENCE_STDOUT)

.PHONY: fclean
fclean:
	$(RM) $(OUT_UNIT_TEST)

.PHONY: re
re: fclean unit-tests

.PHONY: show_vars
show_vars:
	@echo "CFLAGS:          |$(CFLAGS)|"
	@echo "BASE_DIR         |$(BASE_DIR)|"
	@echo "INC_DIRS         |$(INC_DIRS)|"
	@echo "LIB_FILE_NAME    |$(LIB_FILE_NAME)|"
	@echo "INC_DIRS         |$(INC_DIRS)|"
	@echo "LIB_FILE         |$(LIB_FILE)|"
	@echo "CFLAGS           |$(CFLAGS)|"
	@echo "INFLUENCE_STDOUT |$(INFLUENCE_STDOUT)|"
	@echo "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "
	@echo "DEBUG_LAUB_SAN   |$(DEBUG_LAUB_SAN)|"
	@echo "DEBUG_M_SAN      |$(DEBUG_M_SAN)|"
	@echo "DEBUG_VALGRIND   |$(DEBUG_VALGRIND)|"
	@echo "LFLAGS           |$(LFLAGS)|"
