# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    check_variables.mk                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 15:47:14 by reciak            #+#    #+#              #
#    Updated: 2025/10/06 19:11:27 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
# Checking of Variables related to Organization of GNU Make Code
#

ifndef INCLUDED_FROM_DIR
$(error INCLUDED_FROM_DIR must be defined by the including makefile)
endif

ifndef THIS_FILE
$(error THIS_FILE must be defined by all files *.mk in directoy rules)
endif

#
# Checking of local paths to a directory or to directories
#

ifndef LIBFT_DIR
$(error LIBFT_DIR must be defined by the including makefile)
endif

ifndef INC_DIRS
$(error INC_DIRS must be defined by the including makefile)
endif

#
# Checking of local paths to files
#

ifndef DEF_INCS
$(error DEF_INCS must be defined by the including makefile)
endif

ifndef DEF_SRCS
$(error DEF_SRCS must be defined by the including makefile)
endif

ifndef RULE_HYPERLINKS_CLANGD
$(error file path RULE_HYPERLINKS_CLANGD not defined by the including makefile)
endif

ifndef RULE_DOCUMENTATION
$(error file path RULE_RULE_DOCUMENTATION not defined by the including makefile)
endif

ifndef RULE_UPDATE_AND_VIEW
$(error file path RULE_UPDATE_AND_VIEW not defined by the including makefile)
endif

