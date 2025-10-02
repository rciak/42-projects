# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/01 19:35:24 by reciak            #+#    #+#              #
#    Updated: 2025/10/02 18:12:31 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BASE_DIR := ..
#
CR_TEST_DIR := cr_test
#
LIBFT_TESTER_DIR := libftTester
PRINTF_TESTER_DIR := printfTester
#
GNL_ORI_DIR := src/05_get_next_line
GNL_COPY_DIR := tmp_gnl
GNL_TESTER_DIR := $(GNL_COPY_DIR)/gnlTester
GNL_HEADER_ORI_LOC := inc/get_next_line.h

.PHONY: all
all: cr_test \
	 libft_tester_tripouille \
	 printf_tester_tripouille \
	 gnl_tester

.PHONY: cr_test
cr_test: 
	@make -C $(CR_TEST_DIR)

.PHONY: libft_tester_tripouille
libft_tester_tripouille:
	@if [ ! -d $(BASE_DIR)/$(LIBFT_TESTER_DIR) ]; then \
		echo 'Cloning Libft Tester... '; sleep 1; \
		cd $(BASE_DIR) ; \
		git clone git@github.com:Tripouille/libftTester.git; \
		echo; \
		echo 'Making Makefile compatible with my libft ...'; sleep 1; \
		cd $(LIBFT_TESTER_DIR); \
		sed -i '/^CFLAGS[ \t]=*/ s#$$# -I$$(LIBFT_PATH)/inc#' Makefile; \
	fi
	make -C $(BASE_DIR)/$(LIBFT_TESTER_DIR)

.PHONY: printf_tester_tripouille
printf_tester_tripouille:
	@if [ ! -d $(BASE_DIR)/$(PRINTF_TESTER_DIR) ]; then \
		echo 'Cloning Tester for ft_printf'; sleep 1; \
		cd $(BASE_DIR) ; \
		git clone git@github.com:Tripouille/printfTester.git; \
	fi
	make -C $(BASE_DIR)/$(PRINTF_TESTER_DIR)

.PHONY: gnl_tester
gnl_tester:
	mkdir -p $(BASE_DIR)/$(GNL_COPY_DIR)
	@echo "Copying files from get next line project ..."
	rsync $(BASE_DIR)/$(GNL_ORI_DIR)/get_next_line.c \
	      $(BASE_DIR)/$(GNL_COPY_DIR)
	rsync $(BASE_DIR)/$(GNL_ORI_DIR)/get_next_line_utils.c \
	      $(BASE_DIR)/$(GNL_COPY_DIR)
	rsync $(BASE_DIR)/$(GNL_HEADER_ORI_LOC) \
	      $(BASE_DIR)/$(GNL_COPY_DIR)
	rsync $(BASE_DIR)/$(GNL_ORI_DIR)/get_next_line.c \
	      $(BASE_DIR)/$(GNL_COPY_DIR)/get_next_line_bonus.c
	rsync $(BASE_DIR)/$(GNL_ORI_DIR)/get_next_line_utils.c \
	      $(BASE_DIR)/$(GNL_COPY_DIR)/get_next_line_utils_bonus.c
	rsync $(BASE_DIR)/$(GNL_HEADER_ORI_LOC) \
	      $(BASE_DIR)/$(GNL_COPY_DIR)/get_next_line_bonus.h

	@if [ ! -d $(BASE_DIR)/$(GNL_TESTER_DIR) ]; then \
		echo 'Cloning Tester for get_next_line'; sleep 1; \
		cd $(BASE_DIR)/$(GNL_COPY_DIR) ; \
		git clone git@github.com:Tripouille/gnlTester.git; \
	fi
	@make -C $(BASE_DIR)/$(GNL_TESTER_DIR)

.PHONY: re
re: fclean all

.PHONY: fclean
fclean: clean
	rm -fr $(BASE_DIR)/$(GNL_COPY_DIR)
	@make -C $(CR_TEST_DIR) fclean

.PHONY: clean
clean: remove_testers

.PHONY: remove_testers
remove_testers:
	rm -fr $(BASE_DIR)/$(LIBFT_TESTER_DIR)
	rm -fr $(BASE_DIR)/$(PRINTF_TESTER_DIR)
	rm -fr $(BASE_DIR)/$(GNL_TESTER_DIR)

.PHONY: help
help: show_vars

.PHONY: show_vars
show_vars:
	@echo "BASE_DIR            |$(BASE_DIR)|"
	@echo "CR_TEST_DIR         |$(CR_TEST_DIR)|"
	@echo "GNL_ORI_DIR         |$(GNL_ORI_DIR)|"
	@echo "GNL_COPY_DIR        |$(GNL_COPY_DIR)|"
	@echo "GNL_TESTER_DIR      |$(GNL_TESTER_DIR)|"
	@echo "LIBFT_TESTER_DIR    |$(LIBFT_TESTER_DIR)|"
	@echo "PRINTF_TESTER_DIR   |$(PRINTF_TESTER_DIR)|"
	@echo "GNL_HEADER_ORI_LOC  |$(GNL_HEADER_ORI_LOC)|"
	@echo "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "
	@echo "DEBUG_LAUB_SAN      |$(DEBUG_LAUB_SAN)|"
	@echo "DEBUG_M_SAN         |$(DEBUG_M_SAN)|"
	@echo "DEBUG_VALGRIND      |$(DEBUG_VALGRIND)|"
	@echo "VERBOSITY           |$(VERBOSITY)|"

