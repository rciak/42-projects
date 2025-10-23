# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/01 20:46:12 by reciak            #+#    #+#              #
#    Updated: 2025/10/23 09:52:38 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME          := pipex
LIBFT_NAME    := libft.a
LIBFT_DIR     := libft
LIBFT         := $(LIBFT_DIR)/$(LIBFT_NAME)
INC_DIRS      := inc $(LIBFT_DIR)/inc
SRC_DIR       := src
OBJ_DIR       := obj
OBJ_DIR_BONUS := obj

RM       := rm -f
RM_FR    := rm -fr
CC       := cc
CFLAGS    = -std=c99 -Wall -Wextra -Werror $(addprefix -I,$(INC_DIRS))
LDFLAGS  = -L $(LIBFT_DIR) -lft
ifeq ($(DEBUG_LAUB_SAN), 1)
  CFLAGS  += -g3 -fsanitize=address,undefined,leak
  LDFLAGS += -g3 -fsanitize=address,undefined,leak
endif
ifeq ($(DEBUG_M_SAN), 1)
  CFLAGS  += -g3 -fsanitize=memory -fsanitize-memory-track-origins=2
  LDFLAGS += -g3 -fsanitize=memory -fsanitize-memory-track-origins=2
endif
ifeq ($(DEBUG_VALGRIND), 1)
  CFLAGS  += -g3
  LDFLAGS += -g3
endif
ifeq ($(GPROF), 1)
  CFLAGS += -pg
  LDFLAGS += -pg
endif
ifeq ($(OPTI_ON), 1)
  CFLAGS += -O3
  NAME := $(NAME)_O3
endif
### If  VERBOSITY=1  then some more stuff will be printed to stdout
ifeq ($(VERBOSITY), 1)
  COMPILE_COMMAND = $(CC) $(CFLAGS) -c $< -o $@
  LINK_COMMAND =  $(CC) $(OBJS) $(LDFLAGS) -o $(NAME)
else
  COMPILE_COMMAND = @$(CC) $(CFLAGS) -c $< -o $@
  LINK_COMMAND =  @$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)
endif
ifeq ($(CC_LESS_STRICT), 1)
  CFLAGS := $(filter-out -Werror,$(CFLAGS))
endif

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
#############################################
# update via makefile rule (small "m" !)
#   make update_INCS__SRCS__SRCS_BONUS
#############################################
include makefile_dir/def_headers.mk
include makefile_dir/def_sources.mk
#############################################


################################################################################
#  CORE rules                                                                  #
################################################################################

.PHONY: all
all: _print_banner $(NAME)
$(NAME): $(OBJS) $(LIBFT)
	@make --quiet _libft_archive_provided
	@echo 'LINKING object files and libraries ...'
	$(LINK_COMMAND)
	@echo '  --> $(NAME)'


$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(INCS) | $(LIBFT) _entry_message_compile
	@mkdir -p $(@D)
	$(COMPILE_COMMAND)

.PHONY: clean
clean: _print_banner
	@echo 'CLEANING (clean)'
	@echo '  Removing timestamp file (created for bonus part), if any.'
	@$(RM_FR) $(TIMESTAMPFILE_BONUS)
	@echo '  Removing object files, if any.'
	@$(RM_FR) $(OBJS) $(OBJS_BONUS)
	@if [ ! -d $(OBJ_DIR) ]; then \
		: ; \
	elif [ $(OBJ_DIR) = '.' ]; then \
		echo '     Well if the object files would be in their own separte'; \
		echo '     directory that directory shall be removed, but here:'; \
		echo '     Removing the directory . will not even been tried. ...'; \
	else \
		$(RM_FR) $(OBJ_DIR); \
	fi
	@if [ ! -d $(OBJ_DIR_BONUS) ] && [ "$(OBJ_DIR)" = "$(OBJ_DIR_BONUS)" ]; \
	then \
		: ; \
	elif [ $(OBJ_DIR_BONUS) = '.' ]; then \
		echo '     Well if the object files would be in their own separte'; \
		echo '     directory that directory shall be removed, but here:'; \
		echo '     Removing the directory . will not even been tried. ...'; \
	else \
		$(RM_FR) $(OBJ_DIR_BONUS); \
	fi

.PHONY: fclean
fclean: clean
	@echo 'CLEANING (fclean)'
	@echo '  REMOVING $(NAME), if any.' 
	@$(RM_FR) $(NAME)
	@echo '  REMOVING $(NAME)_O3, if any.'
	@$(RM_FR) $(NAME)_O3

.PHONY: re
re: fclean libftre all

.PHONY: re_but_no_libft_rebuilt
re_but_no_libft_rebuilt: fclean all

.PHONY: bonus
bonus: all

################################################################################
#  libft  related rules                                                        #
################################################################################

.PHONY: libftall
libftall: $(LIBFT)

$(LIBFT):
	@make -C  $(LIBFT_DIR) all
	@$(MAKE) _print_banner

.PHONY: libftbonus
libftbonus:
	@make -C $(LIBFT_DIR) bonus

.PHONY: libftre
libftre:
	@make -C $(LIBFT_DIR) re
	@$(MAKE) _print_banner

.PHONY: libftclean
libftclean:
	@make -C $(LIBFT_DIR) clean

.PHONY: libftfclean
libftfclean:
	@make -C $(LIBFT_DIR) fclean

################################################################################
#  helper rules  (not inteded to be used as parameters to make)                #
################################################################################

#Check if libft.a is provided at the expected location
.PHONY: _libft_archive_provided
_libft_archive_provided:
	@echo "CHECKING for $(LIBFT_DIR)/$(LIBFT_NAME) ..."
	@if [ ! -e $(LIBFT_DIR)/$(LIBFT_NAME) ]; \
		then echo "--> Not found!"; exit 1;  \
	fi;

.PHONY: _entry_message_compile
_entry_message_compile:
	@echo 'COMPILING (if need) ...'

PHONY: _print_banner
_print_banner:
	@printf '%b' '$(BANNER)'

################################################################################
# INFO / HELP                                                                  #
################################################################################

.PHONY: help info
help: info 
info:
	@printf "%b\n" '$(INTRO)' | less 

################################################################################
# Def. of larger Output                                                        #
################################################################################

BANNER  := $\
****************************************************************************\n$\
*                                  PIPEX                                   *\n$\
****************************************************************************\n$\

INTRO := $\
****************************************************************************\n$\
*        I N T R O D U C T I O N   T O   T H I S   M A K E F I L E         *\n$\
****************************************************************************\n$\
                                                                            \n$\
I  This Makefile can be run with CONTROL VARIABLES for differnt purposes:   \n$\
                                                                            \n$\
---------                                                                   \n$\
Debugging        CAUTION, cf. section V                                     \n$\
---------                                                                   \n$\
DEBUG_VALGRIND  (For debugging:                                   adds -g3) \n$\
DEBUG_LAUB_SAN  (Leak, Address, Undef. Behaviour;            also adds -g3) \n$\
DEBUG_M_SAN     (Memory;                                     also adds -g3) \n$\
CC_LESS_STRICT  (Remove -Werror flag                                      ) \n$\
                                                                            \n$\
------------                                                                \n$\
Optimazation                                                                \n$\
------------                                                                \n$\
OPTI_ON         (Caution:                                         adds -O3) \n$\
GPROF           (Performance analysis with gprof:                 adds -pg) \n$\
                                                                            \n$\
--------------                                                              \n$\
OUTPUT CONTROL                                                              \n$\
--------------                                                              \n$\
VERBOSITY       (For more output - currently affects only libft, cf. below) \n$\
                                                                            \n$\
HowTo-Example:   make VERBOSITY=1 re                                        \n$\
                                                                            \n$\
                                                                            \n$\
II  RULES that this Makefile provides                                       \n$\
                                                                            \n$\
There are three kinds of rules: User interface rules (II.1), Convenience    \n$\
rules for remote controling libft (II.2) avoiding changing directory, and   \n$\
rules meant to be used only internally / as helpers for other rules (II.3). \n$\
VERY USEFUL rules are also provided in the accompangying makefile (III).    \n$\
                                                                            \n$\
II.1                                                                        \n$\
all:           _print_banner $$(NAME)                                    (1)\n$\
$$(NAME):       $$(OBJS) $$(LIBFT)                                          \n$\
$$(OBJ_DIR)/%.o:$$(SRC_DIR)/%.c $$(INCS) | $$(LIBFT) _entry_message_compile $\
(2) \n$\
clean:         _print_banner                                            (3) \n$\
fclean:        clean                             (also removes the program) \n$\
re:            fclean libftfclean all             (rebuilds - also libft.a) \n$\
bonus:         all                                (currently alias for all) \n$\
help:          info                                       (print this help) \n$\
info:                                                     (print this help) \n$\
                                                                            \n$\
(1) Create the program. Note though that the rule does only require libft.a \n$\
--- to exist but not request a fresh built of libft.a if already existing.  \n$\
--- (even not if some of the sources of libft.a had changed - use           \n$\
---     make re   for building libft.a freshly or run make in libft folder) \n$\
(2) for creating object files from the source files                         \n$\
(3) Removes object files and their folder (unless OBJ := .);                \n$\
--- also a potential timestamp file (in case of bonus) might be deleted.    \n$\
                                                                            \n$\
II.2                                                                        \n$\
libftall:   $$(LIBFT)                                                       \n$\
$$(LIBFT):                                                                  \n$\
libftbonus:                                                                 \n$\
libftclean                                                                  \n$\
libftfclean:                                                                \n$\
---------------------> Note that $$(LIBFT) calls  make -C  $$(LIBFT_DIR) all\n$\
                                                                            \n$\
II.3                                                                        \n$\
Though all GNUmake rule can be called from outside the remaining rules are  \n$\
intended to be called only internally. They are e.g for printing tasks or   \n$\
to ensure that libft.a is provided. These rules might be recognizable       \n$\
by an underscore ('_') prefix character.                                    \n$\
                                                                            \n$\
                                                                            \n$\
III  Rules in  makefile   (small "m"!)                                      \n$\
                                                                            \n$\
In the makefile that should reside next to this Makefile other useful rules \n$\
are defined / included from file in the subfolder makefile_dir/rules, e.g.: \n$\
                                                                            \n$\
******************************************                                  \n$\
* doc                                    *    (Doxgen comments --> html doc)\n$\
* tests                                  *  (runs rule  run_all  in ./tests)\n$\
* update_INCS__SRCS__SRCS_BONUS_and_view *   (updating of INCS and SRCS ...)\n$\
******************************************                                  \n$\
                                                                            \n$\
REMARK: Stuff to remove before project submission:                          \n$\
1. tests                                                                    \n$\
2. makefile,                                                                \n$\
3. makefile_dir                                                             \n$\
                                                                            \n$\
                                                                            \n$\
IV  Potential intersting idea for the future                                \n$\
                                                                            \n$\
rule qa (quality assurance - like tkolar)                                   \n$\
                                                                            \n$\
                                                                            \n$\
V   R E M A R K   T O   U S A G E   O F  S A N I T I Z E R S                \n$\
                                                                            \n$\
When using the sanitizer flags all libraries (in particular libft) need to  \n$\
be compiled with these flags as well. Otherwise the linking should fail.    \n$\
E.g. running     make  DEBUG_M_SAN=1  re; make clean; make all              \n$\
demonstrates this effect.                                                   \n$\
                                                                            \n$\
After debugging remember to turn things back to normal in both              \n$\
libft and the current project by running once    make  re                   \n$\
