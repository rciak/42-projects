# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    doc.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/06 18:24:11 by reciak            #+#    #+#              #
#    Updated: 2025/10/06 19:38:39 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

THIS_FILE := $(RULE_DOCUMENTATION)

ifndef CHECK_VARIABLES 
$(error CHECK_VARIABLES must be defined by the including makefile!) 
endif
include $(CHECK_VARIABLES)

DOXY_OUT_DIR := doc
DOXY_IN_DIRS := inc src

DOXYFILE=$(DOXY_OUT_DIR)/autogen_Doxyfile
# For sed substitions in the Doxyfile
SED_PROJECT_NAME=         PROJECT_NAME           = $(PROJECT_NAME)
SED_OUTPUT_DIRECTORY=     OUTPUT_DIRECTORY       = $(DOXY_OUT_DIR)
SED_INPUT=                INPUT                  = $(DOXY_IN_DIRS)
SED_RECURSIVE=            RECURSIVE              = YES
SED_OPTIMIZE_OUTPUT_FOR_C=OPTIMIZE_OUTPUT_FOR_C  = YES
SED_SOURCE_BROWSER=       SOURCE_BROWSER         = YES


$(DOXY_OUT_DIR): $(SRCS) $(SRCS_BONUS) $(INCS)
	@mkdir -p $(DOXY_OUT_DIR)
	doxygen -g $(DOXYFILE)
	sed -i 's#PROJECT_NAME           =.*#$(SED_PROJECT_NAME)#'     $(DOXYFILE)
	sed -i 's#OUTPUT_DIRECTORY       =.*#$(SED_OUTPUT_DIRECTORY)#' $(DOXYFILE)
	sed -i 's#INPUT                  =.*#$(SED_INPUT)#'            $(DOXYFILE)
	sed -i 's#RECURSIVE              =.*#$(SED_RECURSIVE)#'        $(DOXYFILE)
	sed -i 's#OPTIMIZE_OUTPUT_FOR_C  =.*#$(SED_OPTIMIZE_OUTPUT_FOR_C)#' $(DOXYFILE)
	sed -i 's#SOURCE_BROWSER         =.*#$(SED_SOURCE_BROWSER)#'   $(DOXYFILE)
	doxygen $(DOXYFILE)

.PHONY: docre
docre: docfclean $(DOXY_OUT_DIR)

.PHONY: docclean
docclean:
	rm -fr $(DOXYFILE)

.PHONY: docfclean
docfclean: docclean
	rm -fr $(DOXY_OUT_DIR)

