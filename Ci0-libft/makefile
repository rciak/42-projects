# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Rene Ciak <rciakAT42Vienna@web.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 11:30:19 by Rene Ciak         #+#    #+#              #
#    Updated: 2025/04/26 13:19:32 by Rene Ciak        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include Makefile

.PHONY: update_SRC
update_SRC:
	@echo 'SRC = \'
	@find -name "*.c" \
	  | while read found_files; do echo "$$found_files \\"; done \
	  | sed '$$ s#\\##'

.PHONY: ready_to_submit
ready_to_submit:
	@echo "Not implemented yet beyond this dummy version..."

.PHONY: tests
tests:
	@echo "Not implemented yet beyond this dummy version..."