# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 11:30:19 by reciak            #+#    #+#              #
#    Updated: 2025/10/02 18:20:37 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include Makefile

TEST_DIR:=tests

DOC_DIR:=doc
DOXYFILE=$(DOC_DIR)/autogen_Doxyfile
# For sed substitions in the Doxyfile
SED_PROJECT_NAME=         PROJECT_NAME           = Ci0-libft
SED_OUTPUT_DIRECTORY=     OUTPUT_DIRECTORY       = $(DOC_DIR)
SED_OPTIMIZE_OUTPUT_FOR_C=OPTIMIZE_OUTPUT_FOR_C  = YES
SED_SOURCE_BROWSER=       SOURCE_BROWSER         = YES

################################################################################
# TEST RULES                                                                   #
################################################################################
.PHONY: testsall
testsall: $(TEST_DIR)
	@make -C $(TEST_DIR) all

.PHONY: testsfclean
testsfclean:
	@make -C $(TEST_DIR) fclean

################################################################################
# DOCUMENTATION RULES                                                          #
################################################################################
$(DOC_DIR): $(SRCS) $(SRCS_BONUS) $(INCS)
	@mkdir -p $(DOC_DIR)
	doxygen -g $(DOXYFILE)
	sed -i 's#PROJECT_NAME           =.*#$(SED_PROJECT_NAME)#'     $(DOXYFILE)
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

MAXDEPTH=4           # For find command in rule  update_INCS__SRCS__SRCS_BONUS  

.PHONY: totalclean tclean
totalclean: fclean docfclean testfclean
tclean: totalclean

.PHONY: update_INCS__SRCS__SRCS_BONUS
update_INCS__SRCS__SRCS_BONUS:
	@echo 'INCS := \'
	@find $(SRC_DIR) -maxdepth $(MAXDEPTH) -name "*.h" | sort | \
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

.PHONY: show_vars
show_vars:
	@echo "CFLAGS                    |$(CFLAGS)|"
	@echo "OBJ_DIR                   |$(OBJ_DIR)|"
	@echo "SRCS                      |$(SRCS)|"
	@echo "OBJS                      |$(OBJS)|"
	@echo "SRCS_BONUS                |$(SRCS_BONUS)|"
	@echo "OBJS_BONUS                |$(OBJS_BONUS)|"
	@echo "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "
	@echo "TEST_DIR                  |$(TEST_DIR)|"
	@echo "DOC_DIR                   |$(DOC_DIR)|"
	@echo "DOXYFILE                  |$(DOXYFILE)|"
	@echo "SED_PROJECT_NAME          |$(SED_PROJECT_NAME)|"
	@echo "SED_OUTPUT_DIRECTORY      |$(SED_OUTPUT_DIRECTORY)|"
	@echo "SED_OPTIMIZE_OUTPUT_FOR_C |$(SED_OPTIMIZE_OUTPUT_FOR_C)|"
	@echo "SED_SOURCE_BROWSER        |$(SED_SOURCE_BROWSER)|"
	@echo "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "
	@echo "DEBUG_LAUB_SAN            |$(DEBUG_LAUB_SAN)|"
	@echo "DEBUG_M_SAN               |$(DEBUG_M_SAN)|"
	@echo "DEBUG_VALGRIND            |$(DEBUG_VALGRIND)|"
	@echo "VERBOSITY                 |$(VERBOSITY)|"