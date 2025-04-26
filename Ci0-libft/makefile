# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Rene Ciak <rciakAT42Vienna@web.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 11:30:19 by Rene Ciak         #+#    #+#              #
#    Updated: 2025/04/26 15:15:15 by Rene Ciak        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include Makefile

.PHONY: update_SRCS
update_SRCS:
	@echo 'SRCS := \'
	@find -name "*.c" | \
	  while read found_files; do echo "$$found_files \\"; done | sed '$$ s#\\##'

.PHONY: ready_to_submit
ready_to_submit:
	@echo "Not implemented yet beyond this dummy version..."

.PHONY: tests
tests:
	@echo "Not implemented yet beyond this dummy version..."

.PHONY: show_vars
show_vars:
	@echo "SRC_DIR: |$(SRC_DIR)|"
	@echo "OBJ_DIR: |$(OBJ_DIR)|"
	@echo "SRCS: |$(SRCS)|"
	@echo "OBJS: |$(OBJS)|"