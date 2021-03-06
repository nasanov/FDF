# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nasanov <nasanov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 16:23:11 by nasanov           #+#    #+#              #
#    Updated: 2020/02/21 19:54:40 by nasanov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = draw.c fdf.c read_file.c helper_func.c bonus_func.c key_control_func.c
LIB = libft/libft.a
MINILIBX = minilibx_macos/libmlx.a
LINKER = -framework OpenGL -framework AppKit
OBJ = $(SRCS:.c=.o)

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m
GREEN_COLOR = \033[0;32m

OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING  = "[WARNING]"
COM_STRING   = "[Compiling]"

all: $(NAME)

$(NAME): $(SRCS)
##	@printf "Compiling $@\n"
	@printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@)$(NO_COLOR)\n";
##	@echo "$(COM_COLOR)[Compiling]\t$< -> $@ ..."
	@printf "$(COM_COLOR)[FDF] Compiling 		[#................................................................................................... 01]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[##.................................................................................................. 02]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[###................................................................................................. 03]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[####................................................................................................ 04]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#####............................................................................................... 05]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[######.............................................................................................. 06]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#######............................................................................................. 07]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[########............................................................................................ 08]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#########........................................................................................... 09]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[##########.......................................................................................... 10]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[###########......................................................................................... 11]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[############........................................................................................ 12]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#############....................................................................................... 13]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[##############...................................................................................... 14]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[###############..................................................................................... 15]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[################.................................................................................... 16]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#################................................................................................... 17]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[##################.................................................................................. 18]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[###################................................................................................. 19]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[####################................................................................................ 20]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#####################............................................................................... 21]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[######################.............................................................................. 22]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#######################............................................................................. 23]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[########################............................................................................ 24]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#########################........................................................................... 25]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[##########################.......................................................................... 26]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[###########################......................................................................... 27]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[############################........................................................................ 28]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#############################....................................................................... 29]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[##############################...................................................................... 30]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[###############################..................................................................... 31]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[################################.................................................................... 32]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#################################................................................................... 33]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[##################################.................................................................. 34]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[###################################................................................................. 35]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[####################################................................................................ 36]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#####################################............................................................... 37]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[######################################.............................................................. 38]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#######################################............................................................. 39]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[########################################............................................................ 40]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#########################################........................................................... 41]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[##########################################.......................................................... 42]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[###########################################......................................................... 43]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[############################################........................................................ 44]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#############################################....................................................... 45]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[##############################################...................................................... 46]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[###############################################..................................................... 47]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[################################################.................................................... 48]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#################################################................................................... 49]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[##################################################.................................................. 50]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[###################################################................................................. 51]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[####################################################................................................ 52]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#####################################################............................................... 53]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[######################################################.............................................. 54]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#######################################################............................................. 55]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[########################################################............................................ 56]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#########################################################........................................... 57]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[##########################################################.......................................... 58]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[###########################################################......................................... 59]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[############################################################........................................ 60]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#############################################################....................................... 61]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[##############################################################...................................... 62]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[###############################################################..................................... 63]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[################################################################.................................... 64]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#################################################################................................... 65]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[##################################################################.................................. 66]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[###################################################################................................. 67]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[####################################################################................................ 68]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#####################################################################............................... 69]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[######################################################################.............................. 70]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#######################################################################............................. 71]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[########################################################################............................ 72]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#########################################################################........................... 73]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[##########################################################################.......................... 74]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[###########################################################################......................... 75]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[############################################################################........................ 76]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#############################################################################....................... 77]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[##############################################################################...................... 78]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[###############################################################################..................... 79]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[################################################################################.................... 80]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#################################################################################................... 81]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[##################################################################################.................. 82]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[###################################################################################................. 83]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[####################################################################################................ 84]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#####################################################################################............... 85]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[######################################################################################.............. 86]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#######################################################################################............. 87]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[########################################################################################............ 88]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#########################################################################################........... 89]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[##########################################################################################.......... 90]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[###########################################################################################......... 91]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[############################################################################################........ 92]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#############################################################################################....... 93]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[##############################################################################################...... 94]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[###############################################################################################..... 95]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[################################################################################################.... 96]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#################################################################################################... 97]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[##################################################################################################.. 98]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[###################################################################################################. 99]\r"
	@printf "$(COM_COLOR)[FDF] Compiling 		[#################################################################################################### 100]\r"

	@make -s -C libft
	@gcc -Wall -Wextra -Werror -o $(NAME) $(SRCS) $(LIB) $(MINILIBX) $(LINKER)
	@printf "$(GREEN_COLOR)[DONE]$(NAME) is ready"
##	@echo "\033[44m\033[93m\033[21mfdf...[DONE]\033[49m\033[93m"
	
clean:
	@echo "\033[0;31mRemoving fdf objects...[DONE]\033[49m\033[93m"
	@rm -f $(OBJ)
	@make -C libft clean
fclean: 
##	\033[41m\033[39m\033[1m background
	@echo "\033[0;31mRemoving fdf objects...[DONE]\033[49m\033[93m"
	@rm -f $(NAME)
	@make -C libft fclean

re: 
	make fclean
	make

sanitaise:
	gcc -g -Wall -Wextra -Wshadow -fsanitize=address

norm:
	norminette -R CheckForbiddenSourceHeader $(SRCS)

compile:
	gcc -Wall -Wextra -Werror -c $(SRCS)

.PHONY: 
	all clean fclean re
