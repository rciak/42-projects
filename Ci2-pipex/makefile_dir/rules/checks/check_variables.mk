# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    check_variables.mk                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 15:47:14 by reciak            #+#    #+#              #
#    Updated: 2025/10/04 19:55:24 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef LIBFT_DIR
$(error LIBFT_DIR must be defined by the including makefile!)
endif

ifndef INC_DIRS
$(error INC_DIRS must be defined by the including makefile!)
endif

ifndef DEF_INCS
$(error DEF_INCS must be defined by the including makefile!)
endif

ifndef DEF_SRCS
$(error DEF_SRCS must be defined by the including makefile!)
endif

ifndef RULE_UPDATE_AND_VIEW
$(error RULE_UPDATE_AND_VIEW must be defined by the including makefile!)
endif

