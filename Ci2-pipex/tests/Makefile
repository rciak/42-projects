# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/11 12:35:02 by reciak            #+#    #+#              #
#    Updated: 2025/10/14 20:30:44 by reciak           ###   ########.fr        #
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
LIBFT_DIR_REBASED_HERE := $(BASEDIR)/$(LIBFT_DIR)
#
ifndef INC_DIRS
$(info Undefined: INC_DIRS)
$(info Trying:    INC_DIRS:=libft/inc inc)
INC_DIRS := libft/inc  inc
endif
INC_DIRS_REBASED_HERE := $(addprefix $(BASEDIR)/,$(INC_DIRS))
#
ifndef DEF_SRCS
$(info Undefined: DEF_SRCS)
$(info Trying:    DEF_SRCS:=makefile_dir/def_sources.mk)
DEF_SRCS := makefile_dir/def_sources.mk
endif
DEF_SRCS_REBASED_HERE := $(addprefix $(BASEDIR)/,$(DEF_SRCS))

#Defines the Var SRCS (hopefully) i.e. the sources of the to be tested programm
include $(DEF_SRCS_REBASED_HERE)
SRCS_REBASED_HERE := $(addprefix $(BASEDIR)/,$(SRCS))
SRCS_REBASED_HERE_NO_MAIN := $(filter-out %main.c,$(SRCS_REBASED_HERE))

TEST_BINS := \
	typo_a \
	test_x_error \
	test_miau \
	test_wuff

TEST_BINS := $(addprefix ./,$(TEST_BINS))

CC := clang
CFLAGS := -g3 $(addprefix -I,$(INC_DIRS_REBASED_HERE))
LDFLAGS := -lcriterion -lft -L $(LIBFT_DIR_REBASED_HERE)

.PHONY: all
all: print_test_banner $(TEST_BINS)
	@echo 'Available_tests:'
	@for f in $(TEST_BINS); do \
		echo "  $$f"; \
	done
	@echo 'To execute them all run'
	@echo '  make run_all'
	@echo

#Notes that SRCS might be handed over as SHELL variable from the calling mother
#Makefile, i.e. it might be kinda writeprotected (unless "override" is used)!
test_% : test_%.c $(SRCS_REBASED_HERE_NO_MAIN) | entry_message_compile
	@$(CC) $(CFLAGS) $< $(SRCS_REBASED_HERE_NO_MAIN) $(LDFLAGS) -o $@
	@echo '  $<'

.PHONY: run_all
run_all: print_test_banner  all
	-@for f in $(TEST_BINS); do \
		echo "$$f"; \
		$$f; \
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
