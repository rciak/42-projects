# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    doc.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/06 18:24:11 by reciak            #+#    #+#              #
#    Updated: 2025/10/06 18:26:13 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

THIS_FILE := $(RULE_DOCUMENTATION)

ifndef CHECK_VARIABLES 
$(error CHECK_VARIABLES must be defined by the including makefile!) 
endif
include $(CHECK_VARIABLES)

DOC_DIR:=doc
INC_DIR:=inc
SRC_DIR:=src

DOXYFILE=$(DOC_DIR)/autogen_Doxyfile
# For sed substitions in the Doxyfile
SED_PROJECT_NAME=         PROJECT_NAME           = $(PROJECT_NAME)
SED_INPUT=                INPUT                  = $(INC_DIR) $(SRC_DIR)
SED_OUTPUT_DIRECTORY=     OUTPUT_DIRECTORY       = $(DOC_DIR)
SED_OPTIMIZE_OUTPUT_FOR_C=OPTIMIZE_OUTPUT_FOR_C  = YES
SED_SOURCE_BROWSER=       SOURCE_BROWSER         = YES
SED_RECURSIVE=            RECURSIVE              = YES

$(DOC_DIR): $(SRCS) $(SRCS_BONUS) $(INCS)
	@mkdir -p $(DOC_DIR)
	doxygen -g $(DOXYFILE)
	sed -i 's#PROJECT_NAME           =.*#$(SED_PROJECT_NAME)#'     $(DOXYFILE)
	sed -i 's#INPUT                  =.*#$(SED_INPUT)#'            $(DOXYFILE)
	sed -i 's#OUTPUT_DIRECTORY       =.*#$(SED_OUTPUT_DIRECTORY)#' $(DOXYFILE)
	sed -i 's#OPTIMIZE_OUTPUT_FOR_C  =.*#$(SED_OPTIMIZE_OUTPUT_FOR_C)#' $(DOXYFILE)
	sed -i 's#SOURCE_BROWSER         =.*#$(SED_SOURCE_BROWSER)#'   $(DOXYFILE)
	sed -i 's#RECURSIVE              =.*#$(SED_RECURSIVE)#'        $(DOXYFILE)
	doxygen $(DOXYFILE)

.PHONY: docre
docre: docfclean $(DOC_DIR)

.PHONY: docclean
docclean:
	rm -fr $(DOXYFILE)

.PHONY: docfclean
docfclean: docclean
	rm -fr $(DOC_DIR)

