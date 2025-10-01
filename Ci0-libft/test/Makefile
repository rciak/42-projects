BASE_DIR := ..
LIBFT_TESTER_DIR := libftTester
PRINTF_TESTER_DIR := printfTester
#
GNL_ORI_DIR := src/05_get_next_line
GNL_COPY_DIR := tmp_gnl
GNL_TESTER_DIR := $(GNL_COPY_DIR)/gnlTester
GNL_HEADER_ORI_LOC := inc/get_next_line.h

.PHONY: all
all: libft_tester_tripouille \
	 printf_tester_tripouille \
	 gnl_tester

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
	make -C $(BASE_DIR)/$(GNL_TESTER_DIR)

.PHONY: fclean
fclean: clean
	rm -fr $(BASE_DIR)/$(GNL_COPY_DIR)

.PHONY: clean
clean: remove_testers

.PHONY: remove_testers
remove_testers:
	rm -fr $(BASE_DIR)/$(LIBFT_TESTER_DIR)
	rm -fr $(BASE_DIR)/$(PRINTF_TESTER_DIR)
	rm -fr $(BASE_DIR)/$(GNL_TESTER_DIR)