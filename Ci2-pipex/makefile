# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 11:20:39 by reciak            #+#    #+#              #
#    Updated: 2025/10/05 12:49:11 by reciak           ###   ########.fr        #
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
INCL_FROM_DIR        := .
MAKEFILE_INC_DIR     := makefile_dir
ADDITIONAL_RULES_DIR := makefile_dir/rules

# Files containing Variable Definitions (updatable, see above remark)
DEF_INCS        := $(MAKEFILE_INC_DIR)/def_headers.mk
DEF_SRCS        := $(MAKEFILE_INC_DIR)/def_sources.mk
#
CHECK_VARIABLES      := $(ADDITIONAL_RULES_DIR)/checks/check_variables.mk
RULE_UPDATE_AND_VIEW := \
  $(ADDITIONAL_RULES_DIR)/update_INCS__SRCS__SRCS_BONUS_and_view.mk
include $(RULE_UPDATE_AND_VIEW)

