# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Rene Ciak <rciakAT42Vienna@web.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 11:30:19 by Rene Ciak         #+#    #+#              #
#    Updated: 2025/04/26 19:29:10 by Rene Ciak        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include Makefile

.PHONY: tests
tests:
	@echo "Not implemented yet beyond this dummy version..."

.PHONY: doc
doc:
	@echo "Not implemented yet beyond this dummy version..."

.PHONY: update_INCS__SRCS__SRCS_BONUS
update_INCS__SRCS__SRCS_BONUS:
	@echo 'INCS := \'
	@find $(SRC_DIR) -name "*.h" | \
	  while read found_files; do echo "$$found_files \\"; done | \
	  sed '$$ s# \\##'
	@echo
	@echo 'SRCS := \'
	@find $(SRC_DIR) -name "*.c" | grep --color=none -v "ft_lst" | \
	  while read found_files; do echo "$$found_files \\"; done | \
	  sed '$$ s# \\##'
	@echo
	@echo 'SRCS_BONUS := \'
	@find $(SRC_DIR) -name "*.c" | grep --color=none "ft_lst" | \
	  while read found_files; do echo "$$found_files \\"; done | \
	  sed '$$ s# \\##'

.PHONY: ready_to_submit
ready_to_submit:
	@echo "Not implemented yet beyond this dummy version..."

.PHONY: show_vars
show_vars:
	@echo "OBJ_DIR:    |$(OBJ_DIR)|"
	@echo "SRCS:       |$(SRCS)|"
	@echo "OBJS:       |$(OBJS)|"
	@echo "SRCS_BONUS: |$(SRCS_BONUS)|"
	@echo "OBJS_BONUS: |$(OBJS_BONUS)|"