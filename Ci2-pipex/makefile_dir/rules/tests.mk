# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tests.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/11 11:36:22 by reciak            #+#    #+#              #
#    Updated: 2025/10/11 12:46:04 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

THIS_FILE := $(RULE_TESTS)

#
# REMARK:
#
#   This files shall be included from the makefile (small "m" !) in the
#   base directory (likely the grandparent directory of this file's folder)
#
#   This calling makefile shall define the variables named exactly like
#   in the subsequent checks:
#

ifndef CHECK_VARIABLES 
$(error CHECK_VARIABLES must be defined by the including makefile!) 
endif
include $(CHECK_VARIABLES)

.PHONY: tests
tests:
	@make -C $(TESTS_DIR)