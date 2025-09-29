DIR_BASE = ../
DIR_LIBFT_TESTER = libftTester

.PHONY: all
all: libft_tester_tripouille

.PHONY: libft_tester_tripouille
libft_tester_tripouille:
	@if [ ! -d $(DIR_BASE)/$(DIR_LIBFT_TESTER) ]; then \
		echo 'Cloning Libft Tester... '; sleep 1; \
		cd $(DIR_BASE) ; \
		git clone git@github.com:Tripouille/libftTester.git; \
		echo; \
		echo 'Making Makefile compatible with my libft ...'; sleep 1; \
		cd $(DIR_LIBFT_TESTER); \
		sed -i '/^CFLAGS[ \t]=*/ s#$$# -I$$(LIBFT_PATH)/inc#' Makefile; \
	fi
	make -C $(DIR_BASE)/$(DIR_LIBFT_TESTER)

.PHONY: remove_testers
remove_testers:
	rm -fr $(DIR_BASE)/$(DIR_LIBFT_TESTER)