# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    hyperlinks_clangd.mk                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/05 12:22:22 by reciak            #+#    #+#              #
#    Updated: 2025/10/05 17:10:03 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


THIS_FILE := $(RULE_HYPERLINKS_CLANGD)

#
# REMARK:
#
#   This files shall be included from the makefile (small "m" !) in the
#   base directory (likely the grandparent directory of this file's folder)
#
#   This calling makefile shall define the variables named exactly like
#   in the subsequent checks:
#

#
# NOTE: It seems that in the pipex project so far clangd seems to create
#       correctly working hyperlinks even without the below rule being called
#       / without the thereby created compile_commands.json 
#       Strangely in an earlier project (fractol ?!) there had been issues.
#       This rule will be kept anyway though - one never knows ...
#

ifndef CHECK_VARIABLES 
$(error CHECK_VARIABLES must be defined by the including makefile!) 
endif
include $(CHECK_VARIABLES)

HYCL_TMP_DIR      := very_tmp_build
FOI               := compile_commands.json                   #File Of Interest 
GENERATE_FOI_FLAG := -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
CMAKELISTS        := $(INCLUDED_FROM_DIR)/CMakeLists.txt

# Hopefully the following is not total bullshit ... (no clue about cmake ...)
.PHONY: hyperlinks_clangd
hyperlinks_clangd: _abort_if_cmakelists provide_cmakelists
	@mkdir -p $(HYCL_TMP_DIR)
	@echo 'Calling CMake ...'
	@cmake $(GENERATE_FOI_FLAG) $(INCLUDED_FROM_DIR) -B $(HYCL_TMP_DIR) \
		> /dev/null
	@mv $(HYCL_TMP_DIR)/$(FOI) $(INCLUDED_FROM_DIR)
	@echo '  --> $(FOI)'
	@echo '      (May clangd like it and produce working hyperlinks from it!)'
	@rm -fr $(CMAKELISTS)
	@rm -fr $(HYCL_TMP_DIR)

.PHONY: _abort_if_cmakelists
_abort_if_cmakelists:
	@if [ -e $(CMAKELISTS) ]; then \
		echo 'Refusing to overwrite existing file $(CMAKELISTS)'; \
		exit -1; \
	fi

.PHONY: provide_cmakelists
provide_cmakelists:
	@exec > $(CMAKELISTS); \
		echo 'cmake_minimum_required(VERSION 3.10)'; \
		echo 'project(Dummy_Projectname)'; \
		echo '# Set C standard'; \
		echo 'set(CMAKE_C_STANDARD 99)'; \
		echo '# Add include directories'; \
		echo 'include_directories('; \
		echo '	$${PROJECT_SOURCE_DIR}/inc'; \
		echo '	$${PROJECT_SOURCE_DIR}/libft/inc'; \
		echo ')'; \
		echo '# Collect all source files in src and its subdirectories'; \
		echo 'file(GLOB_RECURSE PROJECT_SRC'; \
		echo '	$${PROJECT_SOURCE_DIR}/src/*.c'; \
		echo '	$${PROJECT_SOURCE_DIR}/libft/*.c'; \
		echo ')'; \
		echo '# Create the executable'; \
		echo 'add_executable(dummy $${PROJECT_SRC})'; 	