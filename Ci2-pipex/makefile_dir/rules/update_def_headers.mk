# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    update_def_headers.mk                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 15:11:09 by reciak            #+#    #+#              #
#    Updated: 2025/10/04 18:08:44 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

THIS_FILE := $(UPDATE_INCS)

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

# The below find command uses the -L flag following symbolic (L)inks.
# To prevent getting caught in an infinite loop the -maxdepth flag is used
MAXDEPTH := 10

# Update the files  $(DEF_INCS)  and  $(DEF_SRCS)
.PHONY: update_INCS__SRCS__SRCS_BONUS
update_INCS__SRCS__SRCS_BONUS:
	@exec > $(DEF_INCS); \
	  echo 'INCS := \'; \
	  find $(INC_DIRS) -maxdepth $(MAXDEPTH) -name "*.h" | sort | \
	    while read found_files; do echo "$$found_files \\"; done | \
	    sed '$$ s# \\##'
	@exec > $(DEF_SRCS); \
	  echo 'SRCS := \' ; \
	  find $(SRC_DIR) -maxdepth $(MAXDEPTH) -name "*.c" | sort | \
	    grep --color=none -v "_bonus" | \
	    while read found_files; do echo "$$found_files \\"; done | \
	    sed '$$ s# \\##' ; \
	  echo ; \
	  echo 'SRCS_BONUS := \' ; \
	  find $(SRC_DIR) -maxdepth $(MAXDEPTH) -name "*.c" | sort | \
	    grep --color=none "_bonus" | \
	    while read found_files; do echo "$$found_files \\"; done | \
	    sed '$$ s# \\##'

# Prints the content of the above files after updating them
.PHONY: update_INCS__SRCS__SRCS_BONUS_and_view
update_INCS__SRCS__SRCS_BONUS_display:  update_INCS__SRCS__SRCS_BONUS
	@cat $(DEF_INCS)
	@echo
	@cat $(DEF_SRCS)
