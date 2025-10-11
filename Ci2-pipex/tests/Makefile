# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/11 12:35:02 by reciak            #+#    #+#              #
#    Updated: 2025/10/11 17:42:16 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BASEDIR := ..
TEST_NAME := TESTS pipex

# Ensure Definitions of Variables LIBFT_DIR and INC_DIRS
ifndef LIBFT
$(info Undefined: LIBFT_DIR)
$(info Trying:    LIBFT_DIR:=libft)
LIBFT_DIR := libft
endif
ifndef INC_DIRS
$(info Undefined: INC_DIRS)
$(info Trying:    INC_DIRS:=libft/inc inc)
INC_DIRS := libft/inc inc
endif

TEST_BINS := \
	typo_a \
	test_miau \
	test_wuff

TEST_BINS := $(addprefix ./,$(TEST_BINS))

CC := clang
CFLAGS := -g3 $(addprefix -I$(BASEDIR)/,$(INC_DIRS))
LDFLAGS := -lcriterion -lft -L $(BASEDIR)/$(LIBFT_DIR)

.PHONY: all
all: print_test_banner $(TEST_BINS)
	@echo 'Available_tests:'
	@for f in $(TEST_BINS); do \
		echo "  $$f"; \
	done
	@echo 'To execute them all run'
	@echo '  make run_all'
	@echo

test_% : test_%.c | entry_message_compile
	@$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
	@echo '  $<'

.PHONY: run_all
run_all: print_test_banner $(TEST_BINS) 
	@for f in $(TEST_BINS); do \
		echo "Executing $$f"; \
		bash -c "$$f"; \
		echo; \
	done

.PHONY: re
re: fclean all

.PHONY: print_test_banner clean
clean:
	rm -fr $(TEST_BINS)

.PHONY: fclean
fclean: print_test_banner clean

################################################################################
# PRINTING RULES                                                               #
################################################################################

PHONY: print_test_banner
print_test_banner:
	@echo '*******************************************************************'
	@echo '*                           TESTS PIPEX                           *'
	@echo '*******************************************************************'

.PHONY: entry_message_compile
entry_message_compile:
	@echo 'COMPILING (if need) ...'
