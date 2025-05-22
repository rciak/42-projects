# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 11:30:19 by Rene Ciak         #+#    #+#              #
#    Updated: 2025/05/22 22:18:57 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include Makefile

TEST_ORIGIN=https://github.com/rciak/$(TEST_DIR).git
TEST_DIR:=42-eva-lua
TEST_SUBDIR:=Ci0-libft-crtests

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
CLONE_IF_NOT_THERE=\
	@if [ -d $(TEST_DIR) ]; then \
	  echo "Directory $(TEST_DIR) already exists.\
	        For cloning freshly delete it first with:";\
	  echo "make testfclean"; \
	else \
	  git clone $(TEST_ORIGIN); \
	fi

.PHONY: install_test
install_test:
	$(CLONE_IF_NOT_THERE)

$(TEST_DIR):
	$(CLONE_IF_NOT_THERE)

.PHONY: unitests
unitests: $(TEST_DIR)
	make -C $(TEST_DIR)/$(TEST_SUBDIR)

.PHONY: testfclean
testfclean:
	rm -fr $(TEST_DIR)

.PHONY: https_autentifcation_to_ssh_autentification
https_autentifcation_to_ssh_autentification:
	make -C $(TEST_DIR) $<

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

# totalclean
.PHONY: totalclean
totalclean: fclean docfclean testfclean
#shortcut for total clean
.PHONY: tclean
tclean: totalclean

.PHONY: update_INCS__SRCS__SRCS_BONUS
update_INCS__SRCS__SRCS_BONUS:
	@echo 'INCS := \'
	@find $(SRC_DIR) -name "*.h" | \
	  while read found_files; do echo "$$found_files \\"; done | \
	  sed '$$ s# \\##'
	@echo
	@echo 'SRCS := \'
	@find $(SRC_DIR) -name "*.c" | grep --color=none -v "ft_lst" | \
	  while read found_files; do echo "$$found_files \\"; done | \
	  sed '$$ s# \\##'
	@echo
	@echo 'SRCS_BONUS := \'
	@find $(SRC_DIR) -name "*.c" | grep --color=none "ft_lst" | \
	  while read found_files; do echo "$$found_files \\"; done | \
	  sed '$$ s# \\##'

.PHONY: ready_to_submit
ready_to_submit:
	@echo "Not implemented yet beyond this dummy version..."

.PHONY: show_vars
show_vars:
	@echo "OBJ_DIR:    |$(OBJ_DIR)|"
	@echo "SRCS:       |$(SRCS)|"
	@echo "OBJS:       |$(OBJS)|"
	@echo "SRCS_BONUS: |$(SRCS_BONUS)|"
	@echo "OBJS_BONUS: |$(OBJS_BONUS)|"
