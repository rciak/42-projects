# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/11 12:35:02 by reciak            #+#    #+#              #
#    Updated: 2025/10/11 15:42:21 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BASEDIR := ..
TEST_NAME := TESTS pipex

ifdef LIBFT_DIR
LIBFT_DIR := $(BASEDIR)/$(LIBFT_DIR)
else
$(info Undefined: LIBFT_DIR)
$(info Trying:    LIBFT_DIR:=$(BASEDIR)/libft)
LIBFT_DIR := $(BASEDIR)/libft
endif

TEST_BINS := \
	typo_a \
	test_miau \
	test_wuff

TEST_BINS := $(addprefix ./,$(TEST_BINS))

CC := clang
CFLAGS := -g3
LDFLAGS := -lcriterion -lft -L $(LIBFT_DIR)

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
	@$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@
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
