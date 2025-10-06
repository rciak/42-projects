# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 11:20:39 by reciak            #+#    #+#              #
#    Updated: 2025/10/05 12:57:06 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# REMARK 1: 
#   If there are both a  Makefile  and  makefile  in the current 
#   working directory then make uses not  Makefile  but  makefile .
#   The first include below thus acts as if 
#   this  makefile  is appended to  Makefile .
#
# REMARK 2
#   INCS and SRCS (and SRCS_BONUS) are defined in the following files;
#   These variables can be automatically updated by running
#     make update_INCS__SRCS__SRCS_BONUS
#   For both updating and displaying the result on screen run
#     make update_INCS__SRCS__SRCS_BONUS
include Makefile 
ifndef LIBFT_DIR
LIBFT_DIR := libft
endif

# Folder definitions
INCLUDED_FROM_DIR    := .
MAKEFILE_INC_DIR     := makefile_dir
ADDITIONAL_RULES_DIR := makefile_dir/rules

# Files containing Variable Definitions (updatable, see above remark)
DEF_INCS        := $(MAKEFILE_INC_DIR)/def_headers.mk
DEF_SRCS        := $(MAKEFILE_INC_DIR)/def_sources.mk
#
CHECK_VARIABLES        := $(ADDITIONAL_RULES_DIR)/checks/check_variables.mk
RULE_HYPERLINKS_CLANGD := $(ADDITIONAL_RULES_DIR)/hyperlinks_clangd.mk
RULE_UPDATE_AND_VIEW   := \
  $(ADDITIONAL_RULES_DIR)/update_INCS__SRCS__SRCS_BONUS_and_view.mk
include $(RULE_HYPERLINKS_CLANGD)
include $(RULE_UPDATE_AND_VIEW)

################################################################################
# DOCUMENTATION RULES                                                          #
################################################################################
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

