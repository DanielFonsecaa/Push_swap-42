MAKE	= make -C

#==============================================================================#
#                                RESOURCES URLS                                #
#==============================================================================#

LIBFT_URL 	= git@github.com:DanielFonsecaa/libft_gnl_printf.git
CHECKER_URL			= https://cdn.intra.42.fr/document/document/32782/checker_linux

#==============================================================================#
#                                     NAMES                                    #
#==============================================================================#

NAME 			= push_swap

### Message Vars
_SUCCESS 		= [$(GRN)SUCCESS$(D)]
_INFO 			= [$(BLU)INFO$(D)]
_NORM 			= [$(MAG)Norminette$(D)]
_NORM_SUCCESS 	= $(GRN)=== OK:$(D)
_NORM_INFO 		= $(BLU)File no:$(D)
_NORM_ERR 		= $(RED)=== KO:$(D)
_SEP 			= =====================

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

SRC_PATH		= src
INC_PATH		= src
LIBS_PATH		= lib
BUILD_PATH		= .build


FILES	= main.c array_length.c convertions.c element.c

SRC						= $(addprefix $(SRC_PATH)/, $(FILES))
OBJS					= $(SRC:$(SRC_PATH)/%.c=$(BUILD_PATH)/%.o)
HEADERS				= $(INC_PATH)/push_swap.h

LIBFT_PATH		= $(LIBS_PATH)/libft
LIBFT_ARC			= $(LIBFT_PATH)/libft.a


#==============================================================================#
#                              COMPILER & FLAGS                                #
#==============================================================================#

CC						= cc

CFLAGS				= -Wall -Wextra -Werror -g

INC						= -I $(INC_PATH)

RM		= rm -rf
AR		= ar rcs
MKDIR_P	= mkdir -p

#==============================================================================#
#                                  RULES                                       #
#==============================================================================#


all: deps $(BUILD_PATH) $(NAME)	## Compile

$(NAME): $(BUILD_PATH) $(LIBFT_ARC) $(CHEKCER_ARC) $(OBJS)			## Compile
	@echo "$(YEL)Compiling $(MAG)$(NAME)$(YEL) mandatory version$(D)"
	$(CC) $(CFLAGS) $(OBJS) $(INC) $(LIBFT_ARC) -o $(NAME)
	@echo "[$(_SUCCESS) compiling $(MAG)$(NAME)$(D) $(YEL)🖔$(D)]"

deps:		## Download/Update deps
	@if test ! -d "$(LIBFT_PATH)"; then make get_libft; \
		else echo "$(YEL)[libft]$(D) folder found 🖔"; fi
	@echo " $(RED)$(D) [$(GRN)Nothing to be done!$(D)]"	

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@echo -n "$(MAG)█$(D)"
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(BUILD_PATH):
	$(MKDIR_P) $(BUILD_PATH)
	@echo "* $(YEL)Creating $(CYA)$(BUILD_PATH)$(YEL) folder:$(D) $(_SUCCESS)"

$(LIBFT_ARC):
	$(MAKE) $(LIBFT_PATH) extra

get_libft:
	@echo "* $(CYA)Getting Libft$(D)"
	@$(MKDIR_P) $(LIBS_PATH)
	git clone $(LIBFT_URL) $(LIBFT_PATH);
	@echo "* $(GRN)Libft submodule download$(D): $(_SUCCESS)"


clean:				## Remove object files
	@echo "*** $(YEL)Cleaning object files$(D)"
	$(RM) $(BUILD_PATH); \
	echo "* $(YEL)Removing $(CYA)$(BUILD_PATH) $(D) folder & files$(D): $(_SUCCESS)"; \

fclean: clean			## Remove executable and .gdbinit
	@echo "*** $(YEL)Cleaning executables$(D)"
	$(RM) $(NAME);
	echo "* $(YEL)Removing $(CYA)$(NAME) $(D) file: $(_SUCCESS)"; \

libclean: fclean	## Remove libs
	@echo "*** $(YEL)Cleaning libraries$(D)"
	$(RM) $(LIBS_PATH)
	@echo "* $(YEL)Removing lib folder & files!$(D) : $(_SUCCESS)"

re: libclean all	## Purge & Recompile

.PHONY: clean fclean re

#==============================================================================#
#                                  UTILS                                       #
#==============================================================================#

# Colors
#
# Run the following command to get list of available colors
# bash -c 'for c in {0..255}; do tput setaf $c; tput setaf $c | cat -v; echo =$c; done'
#
B  		= $(shell tput bold)
BLA		= $(shell tput setaf 0)
RED		= $(shell tput setaf 1)
GRN		= $(shell tput setaf 2)
YEL		= $(shell tput setaf 3)
BLU		= $(shell tput setaf 4)
MAG		= $(shell tput setaf 5)
CYA		= $(shell tput setaf 6)
WHI		= $(shell tput setaf 7)
GRE		= $(shell tput setaf 8)
BRED 	= $(shell tput setaf 9)
BGRN	= $(shell tput setaf 10)
BYEL	= $(shell tput setaf 11)
BBLU	= $(shell tput setaf 12)
BMAG	= $(shell tput setaf 13)
BCYA	= $(shell tput setaf 14)
BWHI	= $(shell tput setaf 15)
D 		= $(shell tput sgr0)
BEL 	= $(shell tput bel)
CLR 	= $(shell tput el 1)