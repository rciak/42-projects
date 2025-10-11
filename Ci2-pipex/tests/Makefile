# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/11 12:35:02 by reciak            #+#    #+#              #
#    Updated: 2025/10/11 14:16:39 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TEST_NAME := TESTS pipex

CC := clang
CFLAGS := -g3
LDFLAGS := -lcriterion

TEST_BINS := \
	typo_a \
	test_miau \
	test_wuff

TEST_BINS := $(addprefix ./,$(TEST_BINS))

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

.PHONY: clean
clean:
	rm -fr $(TEST_BINS)

.PHONY: fclean
fclean: clean

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
