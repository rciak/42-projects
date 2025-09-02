# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    GNUmakefile                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/02 14:34:44 by reciak            #+#    #+#              #
#    Updated: 2025/09/02 19:40:46 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include makefile


define TWINKING_HOLY_SNAIL
      _____________
     /             \\
     \\_____________/
     _______________
    /               \\
   |   O         -   |
   |     \\_____/     |
   |    \\_______/    |
    \\_______________/  
          \\
           \\
            \\
             __________________________
            /                          \\
           | Protesting against a       |
           | questionable rule while    |
           | staying within the rules...|
            \\__________________________/

endef
export TWINKING_HOLY_SNAIL

restore_original_beautiful_colors:
	@printf "$$TWINKING_HOLY_SNAIL"
	@sleep 3
	@echo "********************************************************************"
	@echo "           Restoring beautiful original colors ...                  "
	@echo "********************************************************************"
	@echo	
	@sleep 3
	@echo
	wget -O original_beautiful_colors.c \
	https://raw.githubusercontent.com/rciak/42-projects/c7640d3c7ad40f965825ad40a562d5597ee48a97/Ci2-fractol/src/init_non_mlx_vars/init_palette_first_fractol.c
	@sleep 3
	mv original_beautiful_colors.c src/init_non_mlx_vars/init_palette.c
	@echo
	@echo "********************************************************************"
	@echo "        Compiling fractol with beautiful original colors ...        "
	@echo "********************************************************************"
	@sleep 3
	make fractol
