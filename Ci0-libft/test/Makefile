BASE_DIR := ..
LIBFT_TESTER_DIR := libftTester
PRINTF_TESTER_DIR := printfTester

.PHONY: all
all: libft_tester_tripouille \
     printf_tester_tripouille 

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

.PHONY: remove_testers
remove_testers:
	rm -fr $(BASE_DIR)/$(LIBFT_TESTER_DIR)
	rm -fr $(BASE_DIR)/$(PRINTF_TESTER_DIR)