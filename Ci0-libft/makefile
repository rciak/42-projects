# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 11:30:19 by Rene Ciak         #+#    #+#              #
#    Updated: 2025/05/02 20:06:47 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include Makefile

DOC:=doc
DOXYFILE=$(DOC)/autogen_Doxyfile

# For sed Substitions in the Doxyfile
SED_PROJECT_NAME=         PROJECT_NAME           = Ci0-libft
SED_OUTPUT_DIRECTORY=     OUTPUT_DIRECTORY       = $(DOC)
SED_OPTIMIZE_OUTPUT_FOR_C=OPTIMIZE_OUTPUT_FOR_C  = YES

.PHONY: tests
tests:
	@echo "Not implemented yet beyond this dummy version..."

doc:
	@mkdir -p $(DOC)
	doxygen -g $(DOXYFILE)
	sed -i 's#PROJECT_NAME           =.*#$(SED_PROJECT_NAME)#'     $(DOXYFILE)
	sed -i 's#OUTPUT_DIRECTORY       =.*#$(SED_OUTPUT_DIRECTORY)#' $(DOXYFILE)
	sed -i 's#OPTIMIZE_OUTPUT_FOR_C  =.*#$(SED_OPTIMIZE_OUTPUT_FOR_C)#' $(DOXYFILE)
	doxygen $(DOXYFILE)

.PHONY: redoc
redoc: fclean_doc doc

clean_doc:
	find $(DOC) -name '*$(notdir $(DOXYFILE))*' -type f -delete

.PHONY: fclean_doc
fclean_doc:
	find $(DOC) -name '*$(notdir $(DOXYFILE))*' -type f -delete
	rm -fr $(DOC)/html
	rm -fr $(DOC)/latex
	-rmdir $(DOC)

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