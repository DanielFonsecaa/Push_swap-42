MAKE = make --no-print-directory -C

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
_SUCCESS 		= [$(B)$(GRN)SUCCESS$(D)]
_INFO 			= [$(B)$(BLU)INFO$(D)]
_NORM 			= [$(B)$(MAG)Norminette$(D)]
_NORM_SUCCESS 	= $(B)$(GRN)=== OK:$(D)
_NORM_INFO 		= $(B)$(BLU)File no:$(D)
_NORM_ERR 		= $(B)$(RED)=== KO:$(D)
_SEP 			= =====================

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

SRC_PATH		= src
INC_PATH		= src
LIBS_PATH		= lib
BUILD_PATH		= .build


FILES	= main.c stack.c getters.c checks.c swap.c small.c big.c

SRC						= $(addprefix $(SRC_PATH)/, $(FILES))
OBJS					= $(SRC:$(SRC_PATH)/%.c=$(BUILD_PATH)/%.o)
HEADERS				= $(INC_PATH)/push_swap.h

LIBFT_PATH		= $(LIBS_PATH)/libft
LIBFT_ARC			= $(LIBFT_PATH)/libft.a

CHECKER_PATH		= $(LIBS_PATH)/checker_linux
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

$(NAME): $(BUILD_PATH) $(LIBFT_ARC) $(OBJS)			## Compile
	@echo "   $(B)$(YEL)Compiling $(MAG)$(NAME)$(YEL) mandatory version$(D)"
	@$(CC) $(CFLAGS) $(OBJS) $(INC) $(LIBFT_ARC) -o $(NAME)
	@echo "   [$(B)$(_SUCCESS) compiling $(MAG)$(NAME)$(D) $(YEL)🫰$(D)]"

deps:		## Download/Update deps
	@if test -d "$(LIBFT_PATH)" && test -f "checker_linux"; then \
		echo "   $(B)$(RED)$(D) [$(GRN)Nothing to be done!$(D)]"; fi
	@if test ! -d "$(LIBFT_PATH)"; then make get_libft; \
		else echo "   $(B)$(YEL)[libft]$(D) folder found 🫰"; fi
	@if test ! -f "checker_linux"; then make get_checker; \
		else echo "   $(B)$(YEL)[checker]$(D) file found 🫰"; fi

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@echo -n "$(MAG)█$(D)"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(BUILD_PATH):
	@$(MKDIR_P) $(BUILD_PATH)
	@echo "  $(B)$(YEL)Creating $(CYA)$(BUILD_PATH)$(YEL) folder:$(D) $(_SUCCESS)"

$(LIBFT_ARC):
	@$(MAKE) $(LIBFT_PATH) extra

get_libft:
	@echo "   $(B)$(CYA)Getting Libft$(D)"
	@$(MKDIR_P) $(LIBS_PATH)
	@git clone $(LIBFT_URL) $(LIBFT_PATH);
	@echo "   $(B)$(GRN)Libft submodule download$(D): $(_SUCCESS)"

get_checker:
	@echo "   $(B)$(CYA)Getting Checker submodule$(D)"
	@if test ! -f "checker_linux"; then \
		curl -O $(CHECKER_URL); \
		chmod +x checker_linux; \
		echo "   $(B)$(GRN)Checker submodule download$(D): $(_SUCCESS)"; \
	else \
		echo "   $(B)$(GRN)Checker submodule already exists 🫰"; \
	fi

clean:				## Remove object files
	@echo "   $(B)$(YEL)Cleaning object files$(D)"
	@$(RM) $(BUILD_PATH); 
	@echo "   $(B)$(YEL)Removing $(CYA)$(BUILD_PATH)$(YEL) folder & files$(D): $(_SUCCESS) 🫰"; \

fclean: clean			## Remove executable and .gdbinit
	@echo "   $(B)$(YEL)Cleaning executables$(D)"
	@$(RM) $(NAME);
	@echo "   $(B)$(YEL)Removing $(CYA)$(NAME)$(YEL) file: $(D) $(_SUCCESS) 🫰"; \

libclean: fclean	## Remove libs
	@echo "   $(B)$(YEL)Cleaning libraries$(D)"
	@$(RM) $(LIBS_PATH)
	@$(RM) checker_linux
	@echo "   $(B)$(YEL)Removing $(CYA)lib & checker$(D) : $(_SUCCESS) 🫰"

re: libclean all	## Purge & Recompile

tester:		## Run the tester script
	@echo "   $(B)$(CYA)Running Push Swap Tester$(D)"
	@curl https://raw.githubusercontent.com/hu8813/tester_push_swap/main/pstester.py | python3 -

.PHONY: all deps clean fclean libclean re tester get_libft get_checker

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