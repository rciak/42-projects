# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 11:20:39 by reciak            #+#    #+#              #
#    Updated: 2025/10/11 12:50:38 by reciak           ###   ########.fr        #
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
TESTS_DIR            := tests

# Files containing Variable Definitions (updatable, see above REMARK 2)
DEF_INCS        := $(MAKEFILE_INC_DIR)/def_headers.mk
DEF_SRCS        := $(MAKEFILE_INC_DIR)/def_sources.mk

# File with the checks of variables to somewhat safeguard the below inclusions
# at least if the uncluded files themselve include this rule:
CHECK_VARIABLES        := $(ADDITIONAL_RULES_DIR)/checks/check_variables.mk

# Include Rules
RULE_HYPERLINKS_CLANGD := $(ADDITIONAL_RULES_DIR)/hyperlinks_clangd.mk
RULE_UPDATE_AND_VIEW   := \
  $(ADDITIONAL_RULES_DIR)/update_INCS__SRCS__SRCS_BONUS_and_view.mk
RULE_DOCUMENTATION     := $(ADDITIONAL_RULES_DIR)/doc.mk
RULE_TESTS             := $(ADDITIONAL_RULES_DIR)/tests.mk
include $(RULE_HYPERLINKS_CLANGD)
include $(RULE_UPDATE_AND_VIEW)
include $(RULE_DOCUMENTATION)
include $(RULE_TESTS)
