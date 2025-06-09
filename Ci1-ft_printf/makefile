# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/02 11:15:18 by reciak            #+#    #+#              #
#    Updated: 2025/06/09 14:32:50 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include Makefile

# Without the following one would need to specify manually PROJECT_NAME, e.g.
# PROJECT_NAME := Ci0-libft
# PROJECT_NAME := Ci1-ft_printf
# ...
PATH_MAKEFILE := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
PROJECT_NAME := $(notdir $(patsubst %/,%,$(PATH_MAKEFILE)))

################################################################################
# TEST RULES                                                                   #
################################################################################
TEST_ORIGIN =  https://github.com/rciak/$(TEST_DIR).git
TEST_DIR :=    42-eva-lua
TEST_SUBDIR := $(PROJECT_NAME)-crtests
CLONE_IF_NOT_THERE=\
	@if [ -d $(TEST_DIR) ]; then \
	  echo "Directory $(TEST_DIR) already exists.\
	        For cloning freshly delete it first with:";\
	  echo "make testfclean"; \
	else \
	  git clone $(TEST_ORIGIN); \
	fi

.PHONY: install_test
install_test: $(TEST_DIR)
	$(CLONE_IF_NOT_THERE)

$(TEST_DIR):
	$(CLONE_IF_NOT_THERE)

.PHONY: unit-tests
unit-tests: $(TEST_DIR)
ifeq ($(DEV), 1)
	make -C $(TEST_DIR)/$(TEST_SUBDIR) DEV=1 PRINT_NOTE=0 unit-tests
else
	make -C $(TEST_DIR)/$(TEST_SUBDIR) DEV=0 PRINT_NOTE=0 unit-tests
endif

.PHONY: testfclean
testfclean:
	rm -fr $(TEST_DIR)

.PHONY: https_autentifcation_to_ssh_autentification
https_autentifcation_to_ssh_autentification:
	make -C $(TEST_DIR) $@

################################################################################
# DOCUMENTATION RULES                                                          #
################################################################################
DOC_DIR:=doc
INC_DIR:=inc
SRC_DIR:=src

DOXYFILE=$(DOC_DIR)/autogen_Doxyfile
# For sed substitions in the Doxyfile
SED_PROJECT_NAME=         PROJECT_NAME           = $(PROJECT_NAME)
SED_INPUT=                INPUT                  = $(SRC_DIR) $(INC_DIR)
SED_OUTPUT_DIRECTORY=     OUTPUT_DIRECTORY       = $(DOC_DIR)
SED_OPTIMIZE_OUTPUT_FOR_C=OPTIMIZE_OUTPUT_FOR_C  = YES
SED_SOURCE_BROWSER=       SOURCE_BROWSER         = YES

$(DOC_DIR): $(SRCS) $(SRCS_BONUS) $(INCS)
	@mkdir -p $(DOC_DIR)
	doxygen -g $(DOXYFILE)
	sed -i 's#PROJECT_NAME           =.*#$(SED_PROJECT_NAME)#'     $(DOXYFILE)
	sed -i 's#INPUT                  =.*#$(SED_INPUT)#'            $(DOXYFILE)
	sed -i 's#OUTPUT_DIRECTORY       =.*#$(SED_OUTPUT_DIRECTORY)#' $(DOXYFILE)
	sed -i 's#OPTIMIZE_OUTPUT_FOR_C  =.*#$(SED_OPTIMIZE_OUTPUT_FOR_C)#' $(DOXYFILE)
	sed -i 's#SOURCE_BROWSER         =.*#$(SED_SOURCE_BROWSER)#'   $(DOXYFILE)
	doxygen $(DOXYFILE)

.PHONY: docre
docre: docfclean $(DOC_DIR)

.PHONY: docclean
docclean:
	rm -fr $(DOXYFILE)

.PHONY: docfclean
docfclean: docclean
	rm -fr $(DOC_DIR)

################################################################################
# TOOL RULES                                                                   #
################################################################################

MAXDEPTH=1           # For find command in rule  update_INCS__SRCS__SRCS_BONUS  

.PHONY: totalclean tclean
totalclean: fclean docfclean testfclean libftfclean
tclean: totalclean

.PHONY: update_INCS__SRCS__SRCS_BONUS
update_INCS__SRCS__SRCS_BONUS:
	@echo 'INCS := \'
	@find -L $(LIBFT_DIR) -maxdepth $(MAXDEPTH) -name "*.h" | sort | \
	  while read found_files; do echo "$$found_files \\"; done
	@find $(INC_DIR) -maxdepth $(MAXDEPTH) -name "*.h" | sort | \
	  while read found_files; do echo "$$found_files \\"; done | \
	  sed '$$ s# \\##'
	@echo
	@echo 'SRCS := \'
	@find $(SRC_DIR) -maxdepth $(MAXDEPTH) -name "*.c" | sort | \
	  grep --color=none -v "ft_lst" | \
	  while read found_files; do echo "$$found_files \\"; done | \
	  sed '$$ s# \\##'
	@echo
	@echo 'SRCS_BONUS := \'
	@find $(SRC_DIR) -maxdepth $(MAXDEPTH) -name "*.c" | sort | \
	  grep --color=none "ft_lst" | \
	  while read found_files; do echo "$$found_files \\"; done | \
	  sed '$$ s# \\##'

.PHONY: ready_to_submit
ready_to_submit:
	@echo "Not implemented yet beyond this dummy version..."

.PHONY: show_vars
show_vars:
#	@echo "MAKEFILE_LIST: |$(MAKEFILE_LIST)|"
#	@echo "PATH_MAKEFILE: |$(PATH_MAKEFILE)|"
	@echo "PROJECT_NAME:  |$(PROJECT_NAME)|"
	@echo '-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -'
	@echo "CFLAGS:        |$(CFLAGS)|"
	@echo "LIBFT_DIR:     |$(LIBFT_DIR)|"
	@echo "INC_DIR:       |$(INC_DIR)|"
	@echo "OBJ_DIR:       |$(OBJ_DIR)|"
	@echo "SRCS:          |$(SRCS)|"
	@echo "OBJS:          |$(OBJS)|"
	@echo "SRCS_BONUS:    |$(SRCS_BONUS)|"
	@echo "OBJS_BONUS:    |$(OBJS_BONUS)|"
